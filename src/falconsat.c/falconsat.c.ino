#include <Wire.h>
#include <SparkFunMPL3115A2.h>

MPL3115A2 myPressure;
  
void setup()
{
  Wire.begin(); 
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  myPressure.begin(); 
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  myPressure.setOversampleRate(4); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
}
  
void loop()
{
  digitalWrite(13, HIGH);
  Serial.print("FalconSat running!");
  Serial.println();
  Serial.print("Altitude(m): ");
  Serial.print(myPressure.readAltitude());
  Serial.println();
  Serial.print("Pressure(Pa): ");
  Serial.print(myPressure.readPressure());
  Serial.println();
  Serial.print("Temp(c): ");
  Serial.print(myPressure.readTemp());
  Serial.println();
  Serial.println();
}
