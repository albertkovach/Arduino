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

byte ScreenSelect = 0;
byte MaxScreens = 2;

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






void setup() {
  pinMode(Btn1Pin, INPUT_PULLUP);

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
	switch (ScreenSelect) {
		case 0:
			MainScreen();
		case 1:
			Screen1 ();
		case 2:
			Screen2 ();
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
	TFT.setRotation(2);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, 0);

	TFT.print("Screen 1");
}

void Screen2() {
	TFT.setRotation(2);
	TFT.setFont();
	TFT.setTextSize(2);
	TFT.setTextColor(Yellow, ST7735_BLACK);
	TFT.cp437(true);

	TFT.setCursor(0, 0);

	TFT.print("Screen 2");
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
  
  if (Btn1State != Btn1OldState) {
    Btn1Event();
  }

  Btn1OldState = Btn1State;
}



void Btn1Event() {
	if (ScreenSelect+1 > MaxScreens) {
		ScreenSelect = 0;
	} else {
		ScreenSelect = ScreenSelect++;
	}
	TFT.fillScreen(ST77XX_BLACK);
}
