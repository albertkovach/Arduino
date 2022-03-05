#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
// (RS, E, DB4, DB5, DB6, DB7)

byte customChar[] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000};
  
byte customChar2[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B00000};

boolean tictac = true;
unsigned long currenttime;
unsigned long lastupdatetime;
unsigned long maxupdateperiod = 5000;
char GPUtempCH[4];
char GPUusageCH[4];
char VRAMsizeCH[5];
char CPUtempCH[4];
char CPUusageCH[4];
char RAMsizeCH[6];
int GPUtemp;
int GPUusage;
int VRAMsize;
int CPUtemp;
int CPUusage;
int RAMsize;
const byte SerialPacketLenght = 32;
char receivedChars[SerialPacketLenght];
char tempChars[SerialPacketLenght];
boolean newData = false;
int packetLength = 0;
char question[13];
int questint;





void setup(){ 
  lcd.begin(24, 2);
  Serial.begin(9600);
  lcd.createChar(1, customChar);
  lcd.createChar(2, customChar2); 
}





void loop(){
  ReceptionWithStartEndMarkers();
  RefreshLCD();
  TestMode();
  CheckIfNoData();
}





void ReceptionWithStartEndMarkers() {
    static boolean receptionInProgress = false;
    static byte index = 0;
    char startMarker = '<';
    char endMarker = '>';
    char receivedChar;
 
    while (Serial.available() > 0 && newData == false) {
        receivedChar = Serial.read();

        if (receptionInProgress == true) {
            if (receivedChar != endMarker) {
                receivedChars[index] = receivedChar;
                packetLength++;
                index++;
                if (index >= SerialPacketLenght) {
                    index = SerialPacketLenght - 1;
                }
            }
            else {
                receivedChars[index] = '\0'; // terminate the string
                receptionInProgress = false;
                index = 0;
                newData = true;
            }
        }

        else if (receivedChar == startMarker) {
            receptionInProgress = true;
            packetLength = 0;
        }
    }
}





void TestMode() {
  if (newData == true) {
    newData = false;
    lastupdatetime = millis();
    lcd.setCursor(0, 0);
    lcd.print("Received packet, ");
    lcd.print(packetLength);
    lcd.setCursor(0, 1);
    lcd.print(receivedChars);
  }
}





void RefreshLCD(){
  
  if (newData == true) {
    newData = false;
    lastupdatetime = millis();

    strncpy(question, receivedChars, 12);
    question[13] = '\0';
    if (strcmp (question,"is that you?") == 0) {
      Serial.print("yeah");
      lcd.setCursor(0, 0);
      lcd.print("Discovered             ");
    } else if (packetLength == 26) {
    
    strncpy(GPUtempCH, receivedChars, 3);
    GPUtempCH[3] = '\0';
    GPUtemp = atoi(GPUtempCH)-100;
    strncpy(GPUusageCH, receivedChars+4, 3);
    GPUusageCH[3] = '\0';
    GPUusage = atoi(GPUusageCH)-100;
    strncpy(VRAMsizeCH, receivedChars+8, 4);
    VRAMsizeCH[4] = '\0';
    VRAMsize = atoi(VRAMsizeCH)-1000;
    
    strncpy(CPUtempCH, receivedChars+13, 3);
    CPUtempCH[3] = '\0';
    CPUtemp = atoi(CPUtempCH)-100;
    strncpy(CPUusageCH, receivedChars+17, 3);
    CPUusageCH[3] = '\0';
    CPUusage = atoi(CPUusageCH)-100;
    strncpy(RAMsizeCH, receivedChars+21, 5);
    RAMsizeCH[5] = '\0';
    RAMsize = atoi(RAMsizeCH)-10000;
    
    lcd.setCursor(0, 0);  //GPU 45C  2%  VRAM 498
    lcd.print("GPU");
    if (GPUtemp<100){lcd.print(" ");}
    lcd.print(GPUtemp);
    lcd.print("\1");
    lcd.print("C");
    
    if (GPUusage<10){
    lcd.print("   ");} else if (GPUusage==100) {
    lcd.print(" ");} else { lcd.print("  ");}
    lcd.print(GPUusage);
    lcd.print("%");
    
    if (tictac==true) {
      tictac = false;
      lcd.print("\2");
    } else {
      tictac = true;
      lcd.print(" ");}
    
    lcd.print(" VRAM");
    if (VRAMsize<1000){
    lcd.print("  ");} else if (VRAMsize<100) {
    lcd.print("   ");} else if (VRAMsize<10) {
    lcd.print("    ");} else {}
    lcd.print(VRAMsize);
    
    lcd.setCursor(0, 1);  //CPU 40C 15%  RAM 10234
    lcd.print("CPU");
    if (CPUtemp<100){lcd.print(" ");}
    lcd.print(CPUtemp);
    lcd.print("\1");
    lcd.print("C");
    
    if (CPUusage<10){
    lcd.print("   ");} else if (CPUusage==100) {
    lcd.print(" ");} else { lcd.print("  ");}
    lcd.print(CPUusage);
    lcd.print("%");
    
    lcd.print("  RAM ");
    if (RAMsize<10000){lcd.print(" ");}
    lcd.print(RAMsize);
    }
  } 
}





void CheckIfNoData(){
  currenttime = millis();
  if (currenttime-lastupdatetime >= maxupdateperiod) {
    lcd.setCursor(0, 0);
    lcd.print("No connection           ");
    lcd.setCursor(0, 1);
    lcd.print("                        ");
  }
}


