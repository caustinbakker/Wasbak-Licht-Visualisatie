//Main Code


#include "startup.h"
#include "flow_setup.h"
#include "auto_calibrate.h"
#include "lighting.h"
#include "setup.h"
#include "read_sensor.h"
#include "min_read_sensor.h"
#include "demo_mode.h"

void loop() 
{
//set's base sensor speed
min_read_sensors();
  
//read's sensors
read_sensors();

//remap generator1 value
int waterflow_Value_1 = map(l_hour_1, waterflow_Min1, waterflow_Max1, 0, 255);
int waterflow_Value_2 = map(l_hour_2, waterflow_Min2, waterflow_Max2, 0, 255);

//constrain generator values
waterflow_Value_1 = constrain(waterflow_Value_1, 0, 255);
waterflow_Value_2 = constrain(waterflow_Value_2, 0, 255);

//set color values
warm_color = lighting(warm_color,waterflow_Value_1,1);
cold_color = lighting(cold_color,waterflow_Value_2,1);

//output rgb values

if (0 == 0)
{
    cold_color_up();
    delay(fadespeed);
    cold_color_down();
    delay(fadespeed);
    warm_color_up();
    delay(fadespeed);
    warm_color_down();
    delay(fadespeed);
    cold_color_up();

    warm_color_up();
    delay(fadespeed);
    delay(fadespeed);
    cold_color_down();

    warm_color_down();

}
else
{
  analogWrite(warm_color_pin, warm_color);
  analogWrite(cold_color_pin, cold_color);
}

//serial print change
if (last_warm_color != warm_color or
    last_cold_color != cold_color)
    {
      Serial.print(cold_color);
      Serial.print(" <<>> ");
      Serial.println(warm_color);
    }
}

