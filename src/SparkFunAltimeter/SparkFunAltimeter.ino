//https://learn.sparkfun.com/tutorials/mpl3115a2-pressure-sensor-hookup-guide

#include <Wire.h>
#include <SparkFunMPL3115A2.h>


MPL3115A2 myPressure;


void setup()
{
  Wire.begin();      
  Serial.begin(9600);  

  myPressure.begin(); 
  //myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  myPressure.setOversampleRate(4); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}

void loop()
{
  float altitude = myPressure.readAltitude();
  Serial.print("Altitude(m): ");
  Serial.print(altitude, 2);

  float pressure = myPressure.readPressure();
  Serial.print("; Pressure(Pa): ");
  Serial.print(pressure, 2);

  float temperature = myPressure.readTemp();
  Serial.print("; Temp(c):");
  Serial.print(temperature, 2);

  Serial.println();
}
