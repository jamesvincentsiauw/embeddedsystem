#define led 13
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  if (hallRead()>0){
    digitalWrite(led,LOW);  
  }
  else{
    digitalWrite(led,HIGH);  
  }
}
