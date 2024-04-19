#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);
#define BLYNK_TEMPLATE_ID "*******"
#define BLYNK_TEMPLATE_NAME "******"
#define BLYNK_AUTH_TOKEN "*******"
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHTTYPE DHT11
#include <Servo.h>
Servo myservo;  
DHT dht(D8, DHTTYPE);
const char* ssid = "*****";
const char* password = "*****";
float t = 0;
int po = 90, h, i = 0, a, sy_c, sv_c, sv_a;
WidgetLED led1(V8);
BlynkTimer timer;

void setup() 
{
  lcd.init();                 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ESPRESSIF-NMCU");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM BOOT");
  WiFi.begin(ssid, password);
  int loadingDelay = 300; 
  char animationChars[] = {'|', '/', '-', '\\'};
  int animationCharCount = sizeof(animationChars) / sizeof(animationChars[0]);
  int animationIndex = 0;
  while (WiFi.status() != WL_CONNECTED) 
  {
    lcd.setCursor(17, 3);
    lcd.print(animationChars[animationIndex]);
    animationIndex = (animationIndex + 1) % animationCharCount;
    delay(loadingDelay);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connected to");
  lcd.setCursor(0, 1);
  lcd.print("Wi-Fi network");
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  dht.begin();
  myservo.attach(D4);  
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  myservo.write(po);
  pinMode(A0, INPUT);
}

BLYNK_WRITE(V0)
{
  sy_c = param.asInt();
}

BLYNK_WRITE(V3)
{
  sv_c = param.asInt();
}

BLYNK_WRITE(V4)
{
  sv_a = param.asInt();
}

BLYNK_WRITE(V5)
{
  po = param.asInt();
}

void callsensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature();

  lcd.clear();  // Clear the LCD display
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");
  if (t >= 37.5)
  {
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    led1.off();
  }
  else if(t <=35.5)
  { 
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);
    led1.on();
  }
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, t);
}


void servoin()
{
  a = map(po, 0, 180, -45, 45);
  myservo.write(po);
  Blynk.virtualWrite(V6, a);
  po += 1;
  i++;
}

void servode()
{
  a = map(po, 0, 180, -45, 45);
  myservo.write(po);
  Blynk.virtualWrite(V6, a);
  po = 1;
  i++;
}

void servo_control()
{
  if(sv_c==1)
  {    
    if(sv_a==1)
    {
      a=map(po,-45,45,0,180);
      myservo.write(a);
      Blynk.virtualWrite(V6,po);
    } 
    else if(sv_a==0)
    {
     if(i<=180)
     {
       servoin();
       delay(500);
     }
     else if(i<=360)
     {
       servode();
       delay(500);
     }
     else if(i>360)    
     {
       i=0;
       po=0;
     } 
    }
  } 
  else if(sv_c==0)
  {
    po=90 ;
    a=map(po,0,180,-45,45);
    myservo.write(po);
    Blynk.virtualWrite(V6,a);
  }
}

void read_MQ2_sensor() 
{
  int mq2Value = analogRead(A0);
  float ppm = (mq2Value / 10.0) * 1.5;
  Blynk.virtualWrite(V7, ppm);
}

void loop() 
{
  if (sy_c==1) 
  {
    callsensor();
    servo_control();
    read_MQ2_sensor();
  }
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4); 
  Blynk.syncVirtual(V5);    
  Blynk.run(); 
}
