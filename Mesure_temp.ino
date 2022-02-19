#include <Adafruit_Si7021.h>

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() 
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Start init...");
  if(!sensor.begin())
  {
    Serial.println("Error: no sensor detected. Init failed.");
    while(1);
  }
  Serial.print(" Rev(");
  Serial.print(sensor.getRevision());
  Serial.print(")");
  Serial.print(" Serial #"); Serial.print(sensor.sernum_a, HEX); Serial.println(sensor.sernum_b, HEX);

}

float temp, humid;

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  temp = sensor.readTemperature();
  humid = sensor.readHumidity();
  Serial.print("Temperature: "); Serial.print(temp); Serial.print("°C\t"); Serial.print("Humidity: "); Serial.print(humid); Serial.print("%");
  if(temp < 15)
  {
    // Turn heater ON
    Serial.println("Heater is ON");
  }
  else
  {
    // Turn heater OFF
    Serial.println("Heater is OFF");
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
