#define led 13
void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  pinMode(led, OUTPUT);
}
void loop() {
  if (touchRead(12)>40){
    digitalWrite(led,LOW);  
  }
  else{
    digitalWrite(led,HIGH);  
  }
}
