
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define DEBUG true
#include<LiquidCrystal.h>
#include <SoftwareSerial.h>


//Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);  // Mentioning the kind of LCD used along with the library which we are using in this program
SoftwareSerial bluetooth(9, 8);           // Creates a alternative serial port in pin 2 and 8. In this pin 2 becomes RX of the arduino and pin 8 becomes TX of the arduino.
const int lightPin = 12; //Pin 3 connected to digital output of IR sensor
int lightState = 0;
const int fanpin = 10;
int fanstate = 0;
const int ledpin = 11;
int ledstate = 0;

int p = 0;                                // Initializing to store the value of a variable
float h;
float t;
float f;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(lightPin, INPUT);
  lightState = LOW;
  bluetooth.begin(9600);
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(" Smart Weather");
  lcd.setCursor(0, 1);
  lcd.print(" Monitoring S/M");
  pinMode (fanpin, OUTPUT);
  pinMode (ledpin, OUTPUT);
  fanstate = LOW;
  ledstate = LOW;
  digitalWrite(fanpin, fanstate);
  digitalWrite(ledpin, ledstate);
  delay(2000);
  lcd.clear();
}


void loop()
{
label:
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
  lightState = digitalRead(lightPin);   // Reading inputs from light sensor

  if (isnan(h) || isnan(t) || isnan(f))
  {
    lcd.clear();
    lcd.print("Failed to read ");
    Serial.println("Failed to read");
    bluetooth.println("Failed to read");
    delay(3000);
    return;
  }

  // lcd.clear();
  lcd.print("Hum(%):");
  lcd.print(h);                // Displaying the value of Humidity(percentage) on LCD
  bluetooth.print("Humidity (%): ");
  bluetooth.println(h);
  Serial.print("Humidity (%): ");
  Serial.println(h);

  lcd.setCursor(0, 1);                                // Printing in third line of LCD

  lcd.print("Temp(C):");
  lcd.print(t);             // Displaying the value of Temperature(Degree Celcius) on LCD
  bluetooth.print("Temperature (C): ");
  bluetooth.println(t);
  Serial.print("Temperature (C): ");
  Serial.println(t);
  delay(500);
  if (t > 31)
  { //motor on
    fanstate = HIGH;
    digitalWrite(fanpin, fanstate);
    bluetooth.println("Fan On");
    delay(500);
  }
  if (t < 31)
  { //motor off
    fanstate = LOW;
    digitalWrite(fanpin, fanstate);
    bluetooth.println("Fan Off");
    delay(500);
  }
  lightState = digitalRead(lightPin);   // Reading inputs from light sensor

  if (lightState == HIGH)
  { //light on
    ledstate = HIGH;
    digitalWrite(ledpin, ledstate);
    lcd.setCursor(13, 0);
    lcd.print("/L1");
    bluetooth.println("Light On");
    // delay(500);
  }

  if (lightState == LOW)
  { // light off
    ledstate = LOW;
    digitalWrite(ledpin, ledstate);
    lcd.setCursor(13, 0);
    lcd.print("/L0");
    bluetooth.println
    
    ("Light Off");
    //  delay(500);

  }
}
