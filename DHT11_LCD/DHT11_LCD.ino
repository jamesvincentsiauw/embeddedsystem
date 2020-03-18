#include "DHT.h"
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

#define DHTPIN 4
#define DHTTYPE DHT11

// Inisialisasi DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin();                      
  lcd.backlight();
}

void loop() {
  delay(2000);
  // Baca kelembaban
  float h = dht.readHumidity();
  // Baca suhu dalam Celcius
  float t = dht.readTemperature();

  // Kalo sensor gagal baca, munculin ini
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Sensornya capek gais"));
    lcd.setCursor(0,0);
    lcd.print("sensor error");
    return;
  }

  // Print semua data ke Serial Monitor
  Serial.print(F("Kelembaban : "));
  Serial.print(h);  
  Serial.print(F("%  Suhu: "));
  Serial.print(t);
  Serial.println(F("°C "));
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:     ");
  lcd.print(t);
  lcd.print("C");
}
