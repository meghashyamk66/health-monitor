#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define DHTPIN 2  // DHT11 data pin
#define DHTTYPE DHT11

#define ONE_WIRE_BUS 23  // DS18B20 data pin

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  dht.begin();
  sensors.begin();
}

void loop() {
  // Reading DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Reading DS18B20 sensor
  sensors.requestTemperatures();
  float dsTemperature = sensors.getTempCByIndex(0);

  // Print the values
  Serial.print("DHT11 Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  Serial.print("DS18B20 Temperature: ");
  Serial.println(dsTemperature);
  
  delay(2000);  // Wait for 2 seconds before reading again
}
