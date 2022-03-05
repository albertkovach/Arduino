#include <stdint.h>
#include <EEPROM.h>
#include <KeyboardMultiLanguage.h>
#include "KeyboardMappingRU.h"


int Button1Pin = 4;
int Button1State = 0;
int Button1PrevState = 0;
char Button1Data[100];

int Button2Pin = 5;
int Button2State = 0;
int Button2PrevState = 0; 

int Button3Pin = 6;
int Button3State = 0;
int Button3PrevState = 0; 

int Button4Pin = 7;
int Button4State = 0;
int Button4PrevState = 0; 

String MemoryData[4] = {
  { "нет\n"},
  { "8В-2\n"},
  { "\n \n \n "},
  { "\n"},
};


unsigned int HexToDec(String hexString) {
  unsigned int decValue = 0;
  int nextInt;
  hexString.toUpperCase();
  for (int i = 0; i < hexString.length(); i++)
  {
    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);
    decValue = (decValue * 16) + nextInt;
  }
  return decValue;
}

void KeyOutput(String str) {
  int pos = str.indexOf('§');   // находим начало первой команды
  
  while (pos >= 0)
  {
	  
    if (pos > 0) Keyboard.print(str.substring(0, pos - 1)); // выводим текст до команды и между командами
    str.remove(0, pos + 1);
    char Command = str.charAt(0); // выделяем команды
    pos = str.indexOf(' ');
    String KeyCodeHex = str.substring(1, pos); // выделяем параметр
    byte KeyCodeDec;
    switch (Command)             // команды
    {
      case 'w':
        KeyCodeDec = HexToDec(KeyCodeHex);
        Keyboard.write(KeyCodeDec);
        break;
      case 't':
        delay(KeyCodeHex.toInt());
        break;
      case 'p':
        KeyCodeDec = HexToDec(KeyCodeHex);
        Keyboard.press(KeyCodeDec);
        break;
      case 'r':
        KeyCodeDec = HexToDec(KeyCodeHex);
        Keyboard.release(KeyCodeDec);
        break;
      case 'a':
        Keyboard.releaseAll();
        break;
      case 'l':
        if (KeyCodeHex == "1") Keyboard.language(Russian);
        else Keyboard.language();
        break;
    }
	
    str.remove(0, pos + 1);
    pos = str.indexOf('§'); // находим начало следующей команды
	
  }
  
  
  if (str.length() > 0)Keyboard.print(str); // выводим текст после команды
}

void KeyReadInput() {
  Button1State = digitalRead(Button1Pin);
  Button2State = digitalRead(Button2Pin);
  Button3State = digitalRead(Button3Pin);
  Button4State = digitalRead(Button4Pin);


  if (Button1State == HIGH) {
    if (Button1PrevState == LOW) {
      KeyOutput(MemoryData[0]);
      Button1PrevState = HIGH;
    }
  } else {
    if (Button1PrevState == HIGH) {
      Button1PrevState = LOW;
    }
  }


  if (Button2State == HIGH) {
    if (Button2PrevState == LOW) {
      KeyOutput(MemoryData[1]);
      Button2PrevState = HIGH;
    }
  } else {
    if (Button2PrevState == HIGH) {
      Button2PrevState = LOW;
    }
  }


  if (Button3State == HIGH) {
    if (Button3PrevState == LOW) {
      KeyOutput(MemoryData[2]);
      Button3PrevState = HIGH;
    }
  } else {
    if (Button3PrevState == HIGH) {
      Button3PrevState = LOW;
    }
  }


  if (Button4State == HIGH) {
    if (Button4PrevState == LOW) {
      KeyOutput(MemoryData[3]);
      Button4PrevState = HIGH;
    }
  } else {
    if (Button4PrevState == HIGH) {
      Button4PrevState = LOW;
    }
  }
}

void GetEEPROM() {

}

void PutEEPROM() {

}

void EraseEEPROM() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0xFF);
  }
}

void setup() {
  Serial.begin(9600);
  Keyboard.language(Russian);
  
  pinMode(Button1Pin, INPUT);
  pinMode(Button2Pin, INPUT);
  pinMode(Button3Pin, INPUT);
  pinMode(Button4Pin, INPUT);
}

void loop() {
  KeyReadInput();

}
