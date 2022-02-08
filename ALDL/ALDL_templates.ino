#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

//bool inSync=false;
//bool inMode1=false;
//int dsCounter=0;
//int mdelay=3360;
//const int dataStreamSize=69;
//unsigned char dataStream[dataStreamSize];



//              || NANO || LEO ||
#define TFT_CS      10  //  10
#define TFT_RST     9   //  8
#define TFT_DC      8   //  9

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


//byte M1Command[3] = {0xF4,0x56,0x00};
byte M1Command[4] = {0xF4,0x57,0x01,0x00};
//byte M1Command[] = {0x31,0x31,0x31,0x31}; //summ=3c="<"
byte Preamble[3] = {0xF4,0x95,0x01};
//byte Preamble[] = {0x32,0x32,0x32};






void setup() {

}




void loop() {
	BtnHandler();
	
	if (CycleStarted == 1) {
	}
	
}


void BtnHandler() {
	Btn1State = digitalRead(Btn1Pin);

	if (Btn1State == 0) {
		Btn1PushEvent();
		
		if (Btn1State != Btn1OldState) {
			Btn1ClickEvent();
			Btn1OldState = Btn1State;
		}
	}

}


void Btn1PushEvent() {
	//DebugRequest();
	//CycleStarted = 1;
	//SimpleMainThread();
}


void Btn1ClickEvent() {
	//DebugRequest();
	//CycleStarted = 1;
	//SimpleMainThread();
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
  
	/*	RequestData();
    
	TFT.print("Preamble recieved.. ");
	TFT.println(millis());
  
		RecieveDataBytes();
	*/

	Reciever();
   
	TFT.print("Data bytes recieved.. ");
	TFT.println(millis());
	
	/*
		if (CompareRecievedDataChecksum == true) {
			CalculateRecievedDataChecksum();
      
			TFT.print("  Chck: c-");
			TFT.print(DataBytesCheckSum);
			TFT.print(", t-");
			TFT.println(DataBytes[ByteCount]);
		}
	*/
	
	TFT.println("===================");
	
		DecodeData();
	
		SimpleRefreshScreen();
	
	  Serial.flush();
	delay(RefreshRate);
}







//////////        Вспомогательное       //////////
//----------------------------------------------//


void RequestDataWithoutPreamble() {
	// Начало полной сборки М1
	int M1FullCommandLenght = sizeof(M1Command)+1;
	byte M1FullCommand [M1FullCommandLenght];
	int PreambleLenght = sizeof(Preamble);
	
	for (i = 0; i < sizeof(M1Command); i = i+1) {
		M1FullCommand[i] = M1Command[i]; }
	M1FullCommand[M1FullCommandLenght-1] = checksum_generate(M1Command, sizeof(M1Command));

	i=0;
	while (i < M1FullCommandLenght) {
		Serial.write(M1FullCommand[i]);
		i++; 
	}
}




void HEXDataOutput() {  // Не проверен, не используется
	int linecount = 10;
	int bytecounter = 0;
	
	int j=1;
	while (j<ByteCount +1) {
		TFT.print(DataBytes[j], HEX);
		j++;
		bytecounter++;
		if (bytecounter >= linecount) {  // check if time for new line
			bytecounter = 0;             // Reset byte count for next line
			TFT.println("");             // add a new line
		}
		else {
			TFT.print(" ");              // or add a space
		}
	}
	TFT.println("");
}




void DelayForOtherSoftware() {
	// The following code implements a delay with an incoming serial buffer purge to allow it to run alongside other data captures such as TunerPro - Artduino Tx1 is disconnected
	// Not keeping the incoming serial buffer empty before the next command and read loop causes a parity error
	unsigned long StartTime = millis();                           // Get the starting time value
	while (millis() < StartTime +3000) {                           // Wait for 3000 milliseconds - allows user to read the displayed data
		if (Serial.available() > 0) ALDLbyte = Serial.read();     // Check for available data on the serial port and throw it away - i.e. flush the buffer
	}
}




float T_interpolate(byte DS_Temp) {                                      // Subroutine to interpolate MAT temperature from data stream
                                                                         // Input data is one byte of AD from the temperature thermistor (Very Non Linear)
//Temperature scale for interpolating air temperature taken from the ADS file There are 38 values in the table ranging from -40C for a value of 1 to 200 C for a value of 256
  const float TempScale[38] = {1,5,6,9,11,15,19,25,31,38,47,57,67,79,91,104,117,130,142,154,164,175,184,192,200,206,212,217,222,226,230,233,235,238,240,242,244,256};  // Data Values (38)
  const float TempValue[38] = {-40,-30,-25,-20,-15,-10,-5,0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,200}; // Temp Values (38)
  float T_Range;                                                          // Interpolation range
  float T_Diff;                                                           // Difference between input value and the bottom of the interpolation range
  float TempRange;                                                        // Difference between points on the output value scale
  float Temperature;                                                      // Interpolated Temperature value
  int i = 0;
  while (i<38)                                                            // Loop through increasing values to find start of the interpolation
    {
      if  (TempScale[i]> DS_Temp) break;                                  // Until a higher value is found - exit with i pointing to the higher value for interpolation
      i++;
    }
  if (i>0)                                                                // Figure out the linear interpolation range and difference along the scale
    {
      T_Range = TempScale[i] - TempScale[i-1];                            // Range between these points along the input scale (all calculated as a floating point)
      T_Diff =  DS_Temp - TempScale[i-1];                                 // Difference between data and the lower point
      TempRange = TempValue[i] - TempValue[i-1];                          // Difference between points along the output value scale  
      Temperature =  TempValue[i-1] + (T_Diff/T_Range)*TempRange;         // Interpolated Temperature
    }
  else Temperature = TempValue[0];                                        // unless the input date is <= to the bottom of the scale and the minimum value is used

  return Temperature;                                                     // Return the interpolated temperature
                                              
}




byte checksum_generate(byte *buf, int len) {
  //  Checksum is 2's complement of sum of all bytes in the message
  #ifdef RETARDED
  retardptr(buf,"checksum buf");
  #endif
  int x = 0;
  unsigned int sum = 0;
  for(x=0;x<len;x++) sum += buf[x];
  return ( 256 - ( sum % 256 ) );
  
  
	/* Checksum Calculation  - Checksum Byte = 0x200 - Sum of all bytes transmitted including the Preamble
	// Two's complement the checksum and cast it to a byte
		i=1;
		CheckTotal = 0x80+0x95+0x01;                                          // First start by summing the preamble bytes
		while (i< (ByteCount))                                               // Add recived bytes to the Checksum
		  {                                                                   // except the Checksum byte ittself
			CheckTotal = CheckTotal + DataBytes[i];                           // add a byte
			i++;
		  }
		CheckSum = 0x200 - CheckTotal; */
}














void RequestData() {
	// Начало полной сборки М1
	int M1FullCommandLenght = sizeof(M1Command)+1;
	byte M1FullCommand [M1FullCommandLenght];
	int PreambleLenght = sizeof(Preamble);
	
	for (i = 0; i < sizeof(M1Command); i = i+1) {
		M1FullCommand[i] = M1Command[i]; }
	M1FullCommand[M1FullCommandLenght-1] = checksum_generate(M1Command, sizeof(M1Command));
	
	// Сборка М1 завершена, начало её отправки
	while (PreambleFound == false) {
		i=0;
		while (i < M1FullCommandLenght) {
			Serial.write(M1FullCommand[i]);
			i++; }
		// Отправка М1 завершена, ожидание Preamble

		i=0;
		PreambleTimer = millis();
		while ((((millis() - PreambleTimer) < 100)) && (PreambleFound == false)) {
			if (Serial.available() > 0) {
				ALDLbyte = Serial.read();
				if (ALDLbyte == Preamble[i]) { 		// Если это i-тый элемент preamble, увеличить индекс 
					i++;
					if (i == PreambleLenght-1) PreambleFound = true;  // Once three characters are found, the preamble has been found, time to read in the data
				} else {  							// If there isn't tch, start over looking from the beginning
					PreambleFound = false;
					i=0;
				}
			}
		}
		
	}
}





void RecieveDataBytes() {
    i = 0;
    while (i < ByteCount && Serial.available() > 0) {   
          
              DataBytes[i] = Serial.read();
              i++;
            
      }
}
