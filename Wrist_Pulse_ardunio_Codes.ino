#include <Wire.h>
#include "MAX30100.h"

// Sampling is tightly related to the dynamic range of the ADC.
// refer to the datasheet for further info
#define SAMPLING_RATE                       MAX30100_SAMPRATE_100HZ

// The LEDs currents must be set to a level that avoids clipping and maximises the
// dynamic range
#define IR_LED_CURRENT                      MAX30100_LED_CURR_50MA
#define RED_LED_CURRENT                     MAX30100_LED_CURR_27_1MA

// The pulse width of the LEDs driving determines the resolution of
// the ADC (which is a Sigma-Delta).
// set HIGHRES_MODE to true only when setting PULSE_WIDTH to MAX30100_SPC_PW_1600US_16BITS
#define PULSE_WIDTH                         MAX30100_SPC_PW_1600US_16BITS
#define HIGHRES_MODE                        true


// Instantiate a MAX30100 sensor class
MAX30100 sensor1;
MAX30100 sensor2;
MAX30100 sensor3;

uint16_t ir1, red1;
uint16_t ir2, red2;
uint16_t ir3, red3;

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

void setup()
{
  Wire.begin();
    Serial.begin(115200);

    Serial.print("Initializing MAX30100..");

    // Initialize the sensor
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    TCA9548A(1);
    if (!sensor1.begin()) {
        Serial.println("Sensor 1 initialization failed");
        for(;;);
    } else {
        Serial.println("Sensor 1 initialized");
    }
      TCA9548A(2);
    if (!sensor2.begin()) {
        Serial.println("Sensor 2 initialization failed");
        for(;;);
    } else {
        Serial.println("Sensor 2 initialized");
    }
     TCA9548A(3);
    if (!sensor3.begin()) {
        Serial.println("Sensor 3 initialization failed");
        for(;;);
    } else {
        Serial.println("Sensor 3 initialized");
    }

    // Set up the wanted parameters
   TCA9548A(1);
    sensor1.setMode(MAX30100_MODE_SPO2_HR);
    sensor1.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
    sensor1.setLedsPulseWidth(PULSE_WIDTH);
    sensor1.setSamplingRate(SAMPLING_RATE);
    sensor1.setHighresModeEnabled(HIGHRES_MODE);

    TCA9548A(2);
    sensor2.setMode(MAX30100_MODE_SPO2_HR);
    sensor2.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
    sensor2.setLedsPulseWidth(PULSE_WIDTH);
    sensor2.setSamplingRate(SAMPLING_RATE);
    sensor2.setHighresModeEnabled(HIGHRES_MODE);

    TCA9548A(3);
    sensor3.setMode(MAX30100_MODE_SPO2_HR);
    sensor3.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
    sensor3.setLedsPulseWidth(PULSE_WIDTH);
    sensor3.setSamplingRate(SAMPLING_RATE);
    sensor3.setHighresModeEnabled(HIGHRES_MODE);
}

void loop()
{ 
 TCA9548A(1);
  sensor1.update();
  TCA9548A(2);
  sensor2.update();
  TCA9548A(3);
  sensor3.update();

  while (sensor1.getRawValues(&ir1, &red1)) {

  sensor1.getRawValues(&ir1, &red1);
  TCA9548A(1);
  sensor2.getRawValues(&ir2, &red2);
  TCA9548A(2);
  sensor3.getRawValues(&ir3, &red2);
  TCA9548A(3);
  Serial.print(ir1);
  Serial.print(",");
  Serial.print(ir2);
  Serial.print(",");
  Serial.println(ir3);    
  }
}