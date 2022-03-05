#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

  Adafruit_SSD1306 display (128, 32, &Wire, 4);

  #define ENC_A 2
  #define ENC_B 3
  #define ENC_TYPE 1
  #define outputSW 4
  int Relay = 5;
  volatile boolean state0, lastState, turnFlag;
  int encCounter = 0;
  int encCounterLastState = 0;
  int swState = 1;
  int swLastState = 1;

  bool ChangeValue = false;
  bool ChangeMode = false;

  int DisplayMode = 0;
  bool InfiniteWork = false;
  
  bool WaitForInterfaceTimer = false;
  bool WaitForInterfaceTimerCompleted = false;
  bool WaitForInterfaceTimerJustStopped = false;
  int WaitForInterfaceTimerMill = 2500;


  bool MainTimersWorks = false;

  bool WorkingTimer = false;
  bool WorkingTimerCompleted = false;
  bool WorkingTimerJustStopped = false;
  unsigned long WorkingTimeoutMin;
  unsigned long WorkingTimeoutMill;


  bool StandstillTimer = false;
  bool StandstillTimerCompleted = false;
  bool StandstillTimerJustStopped = false;
  unsigned long StandstillTimeoutMin;
  unsigned long StandstillTimeoutMill;

  unsigned long CurrentTime;
  unsigned long StartTime;
  unsigned long TargetTimeDifference;
  unsigned long TimeDifference;
  unsigned long TimingTargetMin;
  unsigned long TimingTargetSec;
  unsigned long TimingTargetMill;


 
void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); }
  UpdateDisplay();

  attachInterrupt(1, int0, CHANGE);
  pinMode (Relay, OUTPUT);
}

void UpdateDisplay() {

  if (DisplayMode==0) { // Режим простоя
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.println("Standby");
    display.display();

  } else if (DisplayMode==1) { // Выбор времени работы
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print("Work: ");
    display.println(WorkingTimeoutMin);
    display.setTextSize(1);
    display.print("Standstill: ");
    display.println(StandstillTimeoutMin);
    display.display();

  } else if (DisplayMode==2) { // Выбор времени простоя
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.print("Working: ");
    display.println(WorkingTimeoutMin);
    display.setTextSize(2);
    display.print("Stand: ");
    display.println(StandstillTimeoutMin);
    display.display();

  } else if (DisplayMode==3) { // Нормальная работа
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
    display.print("Working: ");
    display.println(WorkingTimeoutMin);
    display.print("Standstill: ");
    display.println(StandstillTimeoutMin);
    display.setTextSize(2);
    if (InfiniteWork==true) {
      display.print("Continuous work");
    } else {
      display.print("Rem: ");
      display.print(TimingTargetMin);
      display.print(":");
      display.print(TimingTargetSec);
      if (WorkingTimer) {
        display.fillRect(90, 2, 38, 3, WHITE);
      } else if (StandstillTimer) {
        display.fillRect(90, 9, 38, 3, WHITE);
      }
    }
    display.display();
  }
  
  
}

void Timer() {
  if (WaitForInterfaceTimer == true) {
    CurrentTime = millis();

    TimeDifference = CurrentTime - StartTime;
    TargetTimeDifference = TimingTargetMill - TimeDifference;

    if (TargetTimeDifference < 100) {
      WaitForInterfaceTimerCompleted = true;
    }
  }

  if (WorkingTimer == true && MainTimersWorks == true) {
    CurrentTime = millis();

    if (StandstillTimeoutMin == 0) {
      InfiniteWork = true;
    } else {
      InfiniteWork = false;
      TimeDifference = CurrentTime - StartTime;
      TargetTimeDifference = WorkingTimeoutMill - TimeDifference;
      TimingTargetSec = TargetTimeDifference / 1000;
      TimingTargetMin = TimingTargetSec / 60;
      TimingTargetSec = TimingTargetSec - TimingTargetMin * 60;
      //Serial.println(TargetTimeDifference);

      if (TargetTimeDifference < 500) {
        WorkingTimerCompleted = true;
        StopWorkingTimer();
        StartStandstillTimer();
      }
    }
  }

  if (StandstillTimer == true && MainTimersWorks == true) {
    CurrentTime = millis();
  
    TimeDifference = CurrentTime - StartTime;
    TargetTimeDifference = StandstillTimeoutMill - TimeDifference;
    TimingTargetSec = TargetTimeDifference / 1000;
    TimingTargetMin = TimingTargetSec / 60;
    TimingTargetSec = TimingTargetSec - TimingTargetMin * 60;
    //Serial.println(TargetTimeDifference);

    if (TargetTimeDifference < 500) {
      StandstillTimerCompleted = true;
      StopStandstillTimer();
      StartWorkingTimer();
    }
  }

}


void StartWorkingTimer() {
  if (WorkingTimeoutMin != 0) {
    StartTime = millis();
    WorkingTimer = true;

    TargetTimeDifference = 0;
    TimeDifference = 0;
    TimingTargetMin = 0;
    TimingTargetSec = 0;
    TimingTargetMill = 0;

    //Serial.println("Relay HIGH");
    digitalWrite (Relay, HIGH);
  }
}

void StopWorkingTimer() {
  WorkingTimer = false;
}

void StartStandstillTimer() {
  if (StandstillTimeoutMin != 0) {
    StartTime = millis();
    StandstillTimer = true;

    TargetTimeDifference = 0;
    TimeDifference = 0;
    TimingTargetMin = 0;
    TimingTargetSec = 0;
    TimingTargetMill = 0;

    //Serial.println("Relay LOW");
    digitalWrite (Relay, LOW);
  }
}

void StopStandstillTimer() {
   StandstillTimer = false;
}

void ModeSwitcher() {
    
  if (WaitForInterfaceTimer == true) { // Если таймер интерфейса включен

    if (WaitForInterfaceTimerCompleted == true) { // Если таймер уже кончился
      if (WorkingTimeoutMin != 0) { // Переключение экрана
        DisplayMode = 3;
      } else {
        DisplayMode = 0; }
      WaitForInterfaceTimer = false; // Сбросить и выключить таймер
      WaitForInterfaceTimerCompleted = false;
      WaitForInterfaceTimerJustStopped = true;
      MainTimersWorks = true;
      StartWorkingTimer();
      
    } else { // Таймер еще не кончился, работаем
      if (ChangeValue == true) {
        digitalWrite (Relay, LOW);
        ChangeValue = false;
        if (DisplayMode == 1) { // Выбор времени работы
          WorkingTimeoutMin = encCounter;
          WorkingTimeoutMill = WorkingTimeoutMin * 60;
          WorkingTimeoutMill = WorkingTimeoutMill * 1000;
        } else if (DisplayMode == 2) { // Выбор времени простоя
          StandstillTimeoutMin = encCounter;
          StandstillTimeoutMill = StandstillTimeoutMin * 60;
          StandstillTimeoutMill = StandstillTimeoutMill * 1000;
        }
        TimingTargetMill = WaitForInterfaceTimerMill; // Сброс таймера
        StartTime = millis();
      }
      if (ChangeMode == true) {
        digitalWrite (Relay, LOW);
        ChangeMode = false;
        if (MainTimersWorks == true) {
          MainTimersWorks = false;
        }
        if (DisplayMode == 1) { // Выбор времени работы
          DisplayMode = 2;
          encCounter = StandstillTimeoutMin;
        } else if (DisplayMode == 2) { // Выбор времени простоя
          DisplayMode = 1;
          encCounter = WorkingTimeoutMin;
        }
        TimingTargetMill = WaitForInterfaceTimerMill; // Сброс таймера
        StartTime = millis();
      }

    }

  } else { // Если не включен, проверить и включить
      if (ChangeValue == true) {
        ChangeValue = false;
        WaitForInterfaceTimer = true;  // Запуск таймера
        TimingTargetMill = WaitForInterfaceTimerMill;
        StartTime = millis();
        if (MainTimersWorks == true) {
          MainTimersWorks = false;
        }
        if (DisplayMode == 0 || DisplayMode == 3) {
          DisplayMode = 1;
          encCounter = WorkingTimeoutMin;
        }
      }

      if (ChangeMode == true) {
        ChangeMode = false;
        WaitForInterfaceTimer = true;  // Запуск таймера
        TimingTargetMill = WaitForInterfaceTimerMill;
        StartTime = millis();
        if (MainTimersWorks == true) {
          MainTimersWorks = false;
        }
        if (DisplayMode == 0 || DisplayMode == 3) {
          DisplayMode = 1;
        }
      }
  }

  Timer();
  UpdateDisplay();
}



void int0() {
  state0 = digitalRead(ENC_A);
  if (state0 != lastState) {
    #if (ENC_TYPE == 1)
    turnFlag = !turnFlag;
    if (turnFlag)
    encCounter += (digitalRead(ENC_B) != lastState) ? -1 : 1;
    #else
    encCounter += (digitalRead(ENC_B) != lastState) ? -1 : 1;
    #endif
    lastState = state0;
  }
}

void EncoderHandler() {
  if (encCounter != encCounterLastState) {
    if (encCounter>60) {
      encCounter=0;
    } else if (encCounter<0) {
      encCounter=60;
    }

    encCounterLastState = encCounter;
    ChangeValue = true;
    ModeSwitcher();
  }
}

void SwitchHandler() {
  swState = digitalRead(outputSW);
  if (swState != swLastState) {
    if (swState == 0) {    
      ChangeMode = true;
      ModeSwitcher();
    }
    
    swLastState = swState;    
  }
}



void loop() {
  EncoderHandler();
  SwitchHandler();
  ModeSwitcher();
}











