

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_CS      10
#define TFT_RST     9
#define TFT_DC      8

Adafruit_ST7735 TFT = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
//https://githubmemory.com/repo/newdigate/rgb565_colors
//https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html
//  ArylideYellow 0xE68D
#define Grey 0xAD55
#define Yellow 0xE68D



#define Bit_Set(port,bit_num) (port = port | (0x01 << bit_num))
#define Bit_Clear(port,bit_num) (port = port & ~(0x01 << bit_num))
const int rxControl=5;

int Btn1Pin = 2;
int Btn1State = 0;
int Btn1OldState = 1;

byte M1Command[4] = {0xF4,0x57,0x01,0x00};
byte Preamble[3] = {0xF4,0x95,0x01};



float RPM;
float TPS;
float Speed;
float EngineTemp;
float SparkAdv;
int Integrator;
float InjBPW;
float Batt;
float MAT;
float FuelConsmp;

int KnockCount = 46;
int BLMCell = 53;
int BLMultiplier = 54;
byte IODPORTC = 24;
	byte ACRequest;
	byte BrakeSwitch;
	byte Range1;
	byte Range2;
	byte Range3;
	String CurrentGear;




byte RPMbyte =  33;
byte TPSbyte = 41;
byte SpeedByte = 30;
byte EngTempByte = 14;
byte SparkAdvByteMSB = 44;
byte SparkAdvByteLSB = 45;
byte IntegratorByte = 48;
byte InjBPWbyteMSB = 56;
byte InjBPWbyteLSB = 57;
byte BatteryByte = 15;
byte MATbyte = 62;

byte KnockCountbyte = 46;
byte BLMCellbyte = 53;
byte BLMultiplierbyte = 54;
byte IODPORTCbyte = 24;




byte Offset = 8; //1

int RefreshRate = 100;
bool CompareRecievedDataChecksum = true;
bool RecievedDataChecksumOK = false;

bool PreambleFound = false;
unsigned long PreambleTimer;

int ALDLbyte = 0;
int ByteCount = 65; //64 + M1 + pream == 64 + 8
byte DataBytes[65];

int i;
unsigned long StartTime;
byte DataBytesCheckSum;
byte CycleStarted = 1;
int linecount = 7;
int bytecounter = 0;



	
	

void setup() {
	pinMode(Btn1Pin, INPUT_PULLUP);

	TFT.initR(INITR_BLACKTAB);
	TFT.fillScreen(ST77XX_BLACK);
	TFT.setFont();
	TFT.setTextWrap(false);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	
	TFT.setCursor(0, 0);
	TFT.setTextSize(1);
    TFT.setRotation(0);

	pinMode(rxControl,OUTPUT);
	digitalWrite(rxControl,LOW);
	
	Serial.begin(8192);

    M1PreambleOffset();
}




void loop() {
	//SimpleMainThread();
	MainThread();
}




void MainThread() {
	Reciever();
	DecodeData();
	RefreshScreen();
	
	//delay(RefreshRate);
}




void M1PreambleOffset() {
	RPMbyte = RPMbyte + Offset;
	TPSbyte = TPSbyte + Offset;
	SpeedByte = SpeedByte + Offset;
	EngTempByte = EngTempByte + Offset;
	SparkAdvByteMSB = SparkAdvByteMSB + Offset;
	SparkAdvByteLSB = SparkAdvByteLSB + Offset;
	IntegratorByte = IntegratorByte + Offset;
	InjBPWbyteMSB = InjBPWbyteMSB + Offset;
	InjBPWbyteLSB = InjBPWbyteLSB + Offset;
	BatteryByte = BatteryByte + Offset;
	MATbyte = MATbyte + Offset;
	
	byte KnockCountbyte = KnockCountbyte+ Offset;
	byte BLMCellbyte = BLMCellbyte+ Offset;
	byte BLMultiplierbyte = BLMultiplierbyte+ Offset;
	byte IODPORTCbyte = IODPORTCbyte+ Offset;
}




void Reciever() {
  unsigned long WaitingTime = 100;
  unsigned long StartTime;
  unsigned long TimeDifference = 0;
  
  int M1FullCommandLenght = sizeof(M1Command)+1;
  byte M1FullCommand [M1FullCommandLenght];
  
  for (i = 0; i < sizeof(M1Command); i = i+1) {
    M1FullCommand[i] = M1Command[i]; }
  M1FullCommand[M1FullCommandLenght-1] = checksum_generate(M1Command, sizeof(M1Command));

  i=0;
  
  Bit_Set(PORTD,rxControl);
  while (i < M1FullCommandLenght) {
    Serial.write(M1FullCommand[i]);
    i++; }
  Bit_Clear(PORTD,rxControl);
  
  StartTime = millis();
  
  bytecounter = 0;
  while (TimeDifference < WaitingTime) {
    TimeDifference = millis() - StartTime;
    
    if (Serial.available() > 0) {
      DataBytes[bytecounter] = Serial.read();
      bytecounter++;
      }
  }
  
  Serial.flush();
}




void DecodeData() {
	RPM =  DataBytes[RPMbyte]* 25;
	TPS = DataBytes[TPSbyte]/2.56;
	Speed = DataBytes[SpeedByte]*1.609344;
	EngineTemp = (DataBytes[EngTempByte]*0.75)-40;
	SparkAdv = ((DataBytes[SparkAdvByteMSB]*256) + (DataBytes[SparkAdvByteLSB]))*0.351563;
	Integrator = DataBytes[IntegratorByte];
	InjBPW = ((DataBytes[InjBPWbyteMSB]*256) + (DataBytes[InjBPWbyteLSB]))/65.536;
	Batt = DataBytes[BatteryByte]/10;
	MAT = (DataBytes[MATbyte]*0.75)-40;
	
	FuelConsmp = 235.21 / (Speed / ( 29 * 0.0000212 * RPM * InjBPW));
	
	
	KnockCount = DataBytes[KnockCountbyte];
	BLMCell = DataBytes[BLMCellbyte];
	BLMultiplier = DataBytes[BLMultiplierbyte];
	IODPORTC = DataBytes[IODPORTCbyte];
	
	ACRequest = bitRead(IODPORTC, 0);
	BrakeSwitch = bitRead(IODPORTC, 1);
	Range1 = bitRead(IODPORTC, 2);
	Range2 = bitRead(IODPORTC, 3);
	Range3 = bitRead(IODPORTC, 4);
	PRNDLdecoder();
	
}


void PRNDLdecoder() {
	if (Range1==0 && Range2==1 && Range3 == 1) { CurrentGear = "LOW";}
	if (Range1==1 && Range2==1 && Range3 == 1) { CurrentGear = "D2";}
	if (Range1==1 && Range2==1 && Range3 == 0) { CurrentGear = "D3";}
	if (Range1==1 && Range2==0 && Range3 == 0) { CurrentGear = "D4";}
	if (Range1==1 && Range2==0 && Range3 == 1) { CurrentGear = "P/N";}
	if (Range1==0 && Range2==0 && Range3 == 1) { CurrentGear = "Reverse";}
}


void RefreshScreen() {
  TFT.setRotation(3);
  TFT.setFont();
  TFT.setTextSize(2);
  TFT.setTextColor(Yellow, ST7735_BLACK);
  TFT.cp437(true);

  // "1250 RPM  18%"
  TFT.setCursor(0, 0);
  if (RPM < 10) { TFT.print("   "); }
  if (RPM >= 10 && RPM < 100) { TFT.print("  "); }
  if (RPM >= 100 && RPM < 1000) { TFT.print(" "); }
  TFT.print(RPM, 0);
  TFT.print(" RPM");
  if (TPS < 10) { TFT.print("   "); }
  if (TPS >= 10 && TPS < 100) { TFT.print("  "); }
  if (TPS >= 100) { TFT.print(" "); }
  TFT.print(TPS, 0);
  TFT.print("%");

  // RPM BAR
  int RPMbarWidth = RPM / 55 * 1.6; //160 = 100, 5500 = 100; 1.6 = 55
  TFT.drawRect(0, 20, 160, 10, Grey);
  TFT.fillRect(1, 21, 158, 8, ST7735_BLACK);
  TFT.fillRect(1, 21, RPMbarWidth-2, 8, Yellow);

  // "98 C 110 kmh"
  TFT.setCursor(0, 40);
  if (EngineTemp < 10) { TFT.print("  "); }
  if (EngineTemp >= 10 && EngineTemp < 100) { TFT.print(" "); }
  if (EngineTemp >= 100) { TFT.print(""); }
  TFT.print(EngineTemp, 0);
  TFT.print(" C");
  //TFT.drawChar(37, 40, 0xF8, Yellow, ST7735_BLACK, 2);
  if (Speed < 10) { TFT.print("   "); }
  if (Speed >= 10 && Speed < 100) { TFT.print("  "); }
  if (Speed >= 100) { TFT.print(" "); }
  TFT.print(Speed, 0);
  TFT.print(" kmh");
  //TFT.print(" 98 C 110 kmh");

  // "ad 22.5 d"
  TFT.drawLine(0, 60, 160, 60, Grey);
  TFT.setCursor(0, 66);
  TFT.print(" ad");
  if (SparkAdv < 10) { TFT.print("  "); TFT.print(SparkAdv, 1); }
  if (SparkAdv >= 10 && SparkAdv < 60) { TFT.print(" "); TFT.print(SparkAdv, 1); }
  if (SparkAdv >= 60) { TFT.print("  ERR"); }
  TFT.print(" deg");


  TFT.drawLine(0, 86, 160, 86, Grey);
  TFT.setCursor(0, 92);
  TFT.print(" ");
  if (Integrator < 100) { TFT.print(" "); }
  TFT.print(Integrator);
  if (FuelConsmp < 10) { TFT.print("    "); }
  if (FuelConsmp >= 10 && FuelConsmp < 100) { TFT.print("   "); }
  if (FuelConsmp >= 100) { TFT.print("  "); }
  TFT.print(FuelConsmp, 1);
  TFT.print(" l");
}




//////////       Упрощенный режим       //////////
//----------------------------------------------//

void SimpleMainThread() {
	TFT.fillScreen(ST77XX_BLACK);
	TFT.setCursor(0, 0);
	TFT.print("Auto update: ");
	TFT.println(CycleStarted);
	TFT.setCursor(0, 15);
	
	TFT.print("Requesting.. ");
	TFT.println(millis());

	Reciever();
   
	TFT.print("Data bytes recieved.. ");
	TFT.println(millis());
	
	
	TFT.println("===================");
	
		DecodeData();
	
		SimpleRefreshScreen();
	
	  Serial.flush();
	delay(RefreshRate);
}




void SimpleRefreshScreen() {
	TFT.print ("RPM: ");
	TFT.println(RPM);
	
	TFT.print ("TPS: ");
	TFT.print(TPS);
	TFT.println (" %");   
    
	TFT.print ("Speed: ");
	TFT.print(Speed);
	TFT.println (" KMpH");
	
	TFT.print("EngineTemp: ");
	TFT.print(EngineTemp);
	TFT.println (" C");
	
	TFT.print("SparkAdv: ");
	TFT.print(SparkAdv);
	TFT.println (" Deg");
	
	TFT.print("Integrator: ");
	TFT.println(Integrator);
	
	TFT.print("InjectorPW: ");
	TFT.print(InjBPW);
	TFT.println (" Millis");
	
	TFT.print("Battery: ");
	TFT.print(Batt);
	TFT.println (" V");
	
	TFT.print ("Intake Air: ");
	TFT.print(MAT);
	TFT.println (" C");
}




//////////         Режим отладки        //////////
//----------------------------------------------//

void DebugRequest() {
  unsigned long WaitingTime = 2000;
  unsigned long StartTime;
  unsigned long TimeDifference = 0;
  
  int M1FullCommandLenght = sizeof(M1Command)+1;
  byte M1FullCommand [M1FullCommandLenght];
  
  for (i = 0; i < sizeof(M1Command); i = i+1) {
    M1FullCommand[i] = M1Command[i]; }
  M1FullCommand[M1FullCommandLenght-1] = checksum_generate(M1Command, sizeof(M1Command));
  
  TFT.fillScreen(ST77XX_BLACK);
  TFT.setCursor(0, 0);
  TFT.print("Manual update");
  TFT.setCursor(0, 15);
  TFT.println("M1FullCommand: ");
  for (i = 0; i < M1FullCommandLenght; i = i+1) {
    TFT.print(M1FullCommand[i], HEX); }
  TFT.println("");
  
  i=0;
  
  Bit_Set(PORTD,rxControl);
  while (i < M1FullCommandLenght) {
    Serial.write(M1FullCommand[i]);
    //Serial.print(M1FullCommand[i], BYTE);
    i++; }
  Bit_Clear(PORTD,rxControl);
  
  TFT.print("Requested.. ");
  TFT.println(millis());
  TFT.println("Start waiting.. ");
  StartTime = millis();
  TFT.println("");
  
  bytecounter = 0;
  while (TimeDifference < WaitingTime) {
    TimeDifference = millis() - StartTime;
    
    if (Serial.available() > 0) {
      ALDLbyte = Serial.read();
      
      TFT.print(ALDLbyte, HEX);
      bytecounter++;

      if (bytecounter >= linecount) {
        bytecounter = 0;
        TFT.println("");
      }
      else {
        TFT.print(" ");
      }
    }

  }
  
  Serial.flush();
  TFT.println("");
  TFT.print("Elapsed");
}




//////////        Вспомогательное       //////////
//----------------------------------------------//


byte checksum_generate(byte *buf, int len) {
  #ifdef RETARDED
  retardptr(buf,"checksum buf");
  #endif
  int x = 0;
  unsigned int sum = 0;
  for(x=0;x<len;x++) sum += buf[x];
  return ( 256 - ( sum % 256 ) );
}



void CalculateRecievedDataChecksum() {
	int DataBytesIndex = 0;
	int AllRecievedECMBytesLen = sizeof(Preamble) + sizeof(DataBytes) - 1;  // Потому что последний байт - checksum
	//AllRecievedECMBytesLen = AllRecievedECMBytesLen - 1; // Из-за добавочного байта совместимости, стр.№127
	byte AllRecievedECMBytes[AllRecievedECMBytesLen];
	
	for (i=0; i<sizeof(Preamble); i++) {
		AllRecievedECMBytes[i] = Preamble[i];
	}
	
	for (i=sizeof(Preamble); i<AllRecievedECMBytesLen-1; i++) {
		DataBytesIndex++;
		AllRecievedECMBytes[i] = DataBytes[DataBytesIndex];
	}
	
	DataBytesCheckSum = checksum_generate(AllRecievedECMBytes, AllRecievedECMBytesLen);
	
	if (DataBytesCheckSum == DataBytes[ByteCount-1]) {
		//Checksum GOOD
		RecievedDataChecksumOK = true;
	} else {
		//Checksum ERROR
		RecievedDataChecksumOK = false;
	}
}
