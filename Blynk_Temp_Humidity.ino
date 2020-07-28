#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor
   
#define DHTTYPE DHT22      // DHT 11

#define dht_dpin 13
DHT dht(dht_dpin, DHTTYPE); 

char auth[] = "auth_code";                                                      

char ssid[] = "wifi_name";   
char pass[] = "wifi_password"; 
float t;                                   
float h;



void setup()
{
    Serial.begin(9600);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.begin();
   
}

void loop()
{
  Blynk.run();
  delay(200);
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}
  
  
