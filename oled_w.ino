/*  Dejan Petrovic
 *  April, 28. 2022
 *  mikroBUS C - oled w
 *  mikroBUS D - pressure 4
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    35
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define BMP_SCK  (76)
#define BMP_MISO (74)
#define BMP_MOSI (75)
#define BMP_CS   (78)
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
void setup() {
  Serial.begin(9600);
  pinMode(52, OUTPUT);
  digitalWrite(52, LOW);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  bmp.begin();
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15,25);
  display.print("ITstreet");
  display.display();
  delay(2000);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  float temp = bmp.readTemperature();
  display.print((String)temp+" "+char(247)+"C");
  display.setCursor(0,21);
  float pres = bmp.readPressure()/100;
  display.print((String)pres+" mb");
  display.setCursor(0,42);
  float alt = bmp.readAltitude(1013.25);
  display.print((String)alt+" m");
  
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure()/100);
    Serial.println(" mbar");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();

    display.display();
    delay(2000);

}
