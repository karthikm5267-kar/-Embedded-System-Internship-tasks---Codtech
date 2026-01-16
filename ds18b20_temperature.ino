// Task-1: Temperature Monitoring using DS18B20
// CodTech Embedded Systems Internship

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2   // DS18B20 data pin connected to D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  Serial.println("Temperature Monitoring System Started");
}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);
}

