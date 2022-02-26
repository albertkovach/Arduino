#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

Adafruit_ST7735 TFT = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
//	https://githubmemory.com/repo/newdigate/rgb565_colors
//	https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html
//  ArylideYellow 0xE68D
#define Grey 0xAD55
#define Yellow 0xE68D


int Btn1Pin = 2;
int Btn1State = 0;
int Btn1OldState = 1;

int Btn2Pin = 3;
int Btn2State = 0;
int Btn2OldState = 1;

int Btn3Pin = 4;
int Btn3State = 0;
int Btn3OldState = 1;



byte ScreenSelect = 1;
byte MaxScreens = 4;
byte MinScreens = 0;

float RPM = 0;
float TPS = 0;
float Speed = 0;
float EngineTemp = 0;
float SparkAdv = 0;
int Integrator = 95;
float InjBPW = 0;
float Batt = 14.8;
float MAT = 0;
float FuelConsmp = 0;

int RefreshRate = 5;

int SelectedMenuElement = 0;
int ElementNumber = 2;
int MenuElementSize = 30;
int Otstup = 5;
String	strong[] =  {"exit","1","2","3","4","5","6","7"};





void setup() {
  pinMode(Btn1Pin, INPUT_PULLUP);
  pinMode(Btn2Pin, INPUT_PULLUP);
  pinMode(Btn3Pin, INPUT_PULLUP);

  TFT.initR(INITR_BLACKTAB);
  TFT.fillScreen(ST77XX_BLACK);
  TFT.setTextWrap(false);
}



void loop() {  
	BtnHandler();
	Increment();
	RefreshScreen();
}



void RefreshScreen() {
	if (ScreenSelect==1) {
		MainScreen();
	}
	if (ScreenSelect==2) {
		Screen1();
	}
	if (ScreenSelect==3) {
		Screen2();
	}
	if (ScreenSelect==100) {
		ScreenMenu1();
	}
	if (ScreenSelect==101) {
		ScreenMenu2();
	}
	if (ScreenSelect==111) {
		ScreenSens1();
	}
	if (ScreenSelect==112) {
		ScreenBits1();
	}
	if (ScreenSelect==113) {
		ScreenErr1();
	}
	if (ScreenSelect==121) {
		ScreenSens2();
	}
	if (ScreenSelect==122) {
		ScreenBits2();
	}
	if (ScreenSelect==123) {
		ScreenErr2();
	}
}



void MainScreen() {
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


void Screen1() {
	ElementNumber = 1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);

	TFT.print("Menu");
	TFT.setCursor(0, MenuElementSize+Otstup);

	TFT.print("MainENGINE");
	TFT.setCursor(0, MenuElementSize*2+Otstup);

	TFT.print("MainTRANS");


	TFT.drawLine(0, SelectedMenuElement*MenuElementSize+MenuElementSize, 160, SelectedMenuElement*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, SelectedMenuElement*MenuElementSize+MenuElementSize*2, 160, SelectedMenuElement*MenuElementSize+MenuElementSize*2, Grey);
}

void Screen2() {
	TFT.setRotation(2);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, 50);

	TFT.print("Screen 2");
}


void ScreenMenu1() {
	ElementNumber = 3;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);

	TFT.print("Exit");
	TFT.setCursor(0, MenuElementSize+Otstup);

	TFT.print("SENS");
	TFT.setCursor(0, MenuElementSize*2+Otstup);

	TFT.print("BITS");
	TFT.setCursor(0, MenuElementSize*3+Otstup);

	TFT.print("ERR");
	TFT.drawLine(0, SelectedMenuElement*MenuElementSize+MenuElementSize, 160, SelectedMenuElement*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, SelectedMenuElement*MenuElementSize, 160, SelectedMenuElement*MenuElementSize, Grey);
}


void ScreenMenu2() {
	ElementNumber = 3;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);

	TFT.print("Exit");
	TFT.setCursor(0, MenuElementSize+Otstup);

	TFT.print("Menu1");
	TFT.setCursor(0, MenuElementSize*2+Otstup);

	TFT.print("Menu2");
	TFT.setCursor(0, MenuElementSize*3+Otstup);

	TFT.print("Menu3");
	TFT.drawLine(0, SelectedMenuElement*MenuElementSize+MenuElementSize, 160, SelectedMenuElement*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, SelectedMenuElement*MenuElementSize, 160, SelectedMenuElement*MenuElementSize, Grey);
}


void ScreenSens1() {
	ElementNumber = sizeof(*strong)+1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Sens1");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1){
		TFT.print(strong[SelectedMenuElement-1]);
	}
	
	TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
	TFT.setCursor(0, MenuElementSize*3+Otstup);
	
	if(SelectedMenuElement<ElementNumber){
		TFT.print(strong[SelectedMenuElement+1]);
	}
	
	TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}


void ScreenBits1() {
	ElementNumber = sizeof(*strong)+1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Bits1");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1){
		TFT.print(strong[SelectedMenuElement-1]);
	}
	
	TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
	TFT.setCursor(0, MenuElementSize*3+Otstup);
	
	if(SelectedMenuElement<ElementNumber){
		TFT.print(strong[SelectedMenuElement+1]);
	}
	
	TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}


void ScreenErr1() {
	ElementNumber = sizeof(*strong)+1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Err1");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1){
		TFT.print(strong[SelectedMenuElement-1]);
	}
	
	TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
	TFT.setCursor(0, MenuElementSize*3+Otstup);

	if(SelectedMenuElement<ElementNumber){
		TFT.print(strong[SelectedMenuElement+1]);
	}
	
	TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}


void ScreenSens2() {
	ElementNumber = sizeof(*strong)+1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Sens2");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1)TFT.print(strong[SelectedMenuElement-1]);
		TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
			TFT.setCursor(0, MenuElementSize*3+Otstup);
	if(SelectedMenuElement<ElementNumber)TFT.print(strong[SelectedMenuElement+1]);
		TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}


void ScreenBits2() {
	ElementNumber = sizeof(*strong)+1;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Bits2");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1){
		TFT.print(strong[SelectedMenuElement-1]);
	}
	
	TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
	TFT.setCursor(0, MenuElementSize*3+Otstup);
	
	if(SelectedMenuElement<ElementNumber){
		TFT.print(strong[SelectedMenuElement+1]);
	}
	
	TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}


void ScreenErr2() {
	ElementNumber = 7;
	TFT.setRotation(3);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, Otstup);
	TFT.print("Err2");
	TFT.setCursor(0, MenuElementSize+Otstup);
	
	if(SelectedMenuElement>=1){
		TFT.print(strong[SelectedMenuElement-1]);
	}
	
	TFT.setCursor(0, MenuElementSize*2+Otstup);
	TFT.print(strong[SelectedMenuElement]);
	TFT.setCursor(0, MenuElementSize*3+Otstup);
	
	if(SelectedMenuElement<ElementNumber){
		TFT.print(strong[SelectedMenuElement+1]);
	}
	
	TFT.drawLine(0, 2*MenuElementSize+MenuElementSize, 160, 2*MenuElementSize+MenuElementSize, Grey);
	TFT.drawLine(0, 2*MenuElementSize, 160, 2*MenuElementSize, Grey);
}





void Increment() {
  RPM = RPM + 150;
  if (RPM > 5500) RPM = 0;

  TPS = TPS + 5;
  if (TPS > 100) TPS = 0;

  Speed = Speed + 10;
  if (Speed > 170) Speed = 0;

  EngineTemp = EngineTemp + 15;
  if (EngineTemp > 130) EngineTemp = 0;

  SparkAdv = SparkAdv + 8.5;
  if (SparkAdv > 70) SparkAdv = 0;

  Integrator = Integrator + 15;
  if (Integrator > 180) Integrator = 95;

  FuelConsmp = FuelConsmp + 5;
  if (FuelConsmp > 110) FuelConsmp = 0;

}






void BtnHandler() {
	Btn1State = digitalRead(Btn1Pin);
	Btn2State = digitalRead(Btn2Pin);
	Btn3State = digitalRead(Btn3Pin);

	if (Btn1State == 0) {
		Btn1PushEvent();
		if (Btn1State != Btn1OldState) {
			Btn1ClickEvent();
			Btn1OldState = Btn1State;
		}
	} else {
		Btn1OldState = 1;
	}
	
	if (Btn2State == 0) {
		Btn2PushEvent();
		if (Btn2State != Btn2OldState) {
			Btn2ClickEvent();
			Btn2OldState = Btn2State;
		}
	} else {
		Btn2OldState = 1;
	}
	
	if (Btn3State == 0) {
		Btn3PushEvent();
		if (Btn3State != Btn3OldState) {
			Btn3ClickEvent();
			Btn3OldState = Btn3State;
      }
	} else {
		Btn3OldState = 1;
	}

}




void Btn1PushEvent() {
}

void Btn1ClickEvent() {
	if (ScreenSelect==2&&SelectedMenuElement==0) {
		ScreenSelect = 100;
	} else if (ScreenSelect==2&&SelectedMenuElement==1) {
		ScreenSelect = 101;
	} else if (ScreenSelect>=100&&SelectedMenuElement==0){
		ScreenSelect = 1;
	} else if (ScreenSelect==100&&SelectedMenuElement!=0){
		ScreenSelect = 110+SelectedMenuElement;
		SelectedMenuElement =1;
	} else if (ScreenSelect==101&&SelectedMenuElement!=0){
		ScreenSelect = 120+SelectedMenuElement;
		SelectedMenuElement = 1;
	}

	TFT.fillScreen(ST77XX_BLACK);
}





void Btn2PushEvent() {
}

void Btn2ClickEvent() {
	if (ScreenSelect >= 100 || ScreenSelect ==2){
		SelectedMenuElement++;
		if (SelectedMenuElement>ElementNumber){
			SelectedMenuElement =0;
		}
	} else {
		ScreenSelect = ScreenSelect + 1;
		if (ScreenSelect >= MaxScreens) {
			ScreenSelect = 1;
		}
	}
	TFT.fillScreen(ST77XX_BLACK);
}





void Btn3PushEvent() {
}

void Btn3ClickEvent() {
	if (ScreenSelect >= 100 || ScreenSelect ==2) {
		SelectedMenuElement=SelectedMenuElement-1;
		if (SelectedMenuElement<0){
			SelectedMenuElement =ElementNumber;
		}
	} else {
		ScreenSelect = ScreenSelect - 1;
		if (ScreenSelect <= MinScreens) {
			ScreenSelect = MaxScreens-1;
		}
	}
	TFT.fillScreen(ST77XX_BLACK);
}
