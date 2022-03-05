int Button1Pin = 8;
int Button2Pin = 9;

int Button1State = 0;
int Button2State = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(Button1Pin, INPUT);
  pinMode(Button2Pin, INPUT);

}

void loop() {
  Button1State = digitalRead(Button1Pin);
  Button2State = digitalRead(Button2Pin);
  
  Serial.print("button data:");
  Serial.print(Button1State);
  Serial.println(Button2State);
}
