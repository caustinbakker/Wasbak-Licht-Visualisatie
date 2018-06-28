//waterflow sensors
  volatile int  flow_frequency_1;  // Measures flow meter pulses
  volatile int  flow_frequency_2;  // Measures flow meter pulses
  unsigned int  l_hour_1;          // Calculated litres/hour       
  unsigned int  l_hour_2; 
  unsigned char flowmeter_1 = 2;  // Flow Meter Pin number
  unsigned char flowmeter_2 = 3;
  unsigned long currentTime;
  unsigned long cloopTime;
//RGB verlichting pins
  #define warm_color_pin 10
  #define cold_color_pin 11
//generator1 values
  int waterflow_Value_1 = 0;
  int waterflow_Min1 = 0;
  int waterflow_Max1 = 0;
//generator2 values
  int waterflow_Value_2 = 0;
  int waterflow_Min2 = 0;
  int waterflow_Max2 = 0;
//run void setup 1x
  int warm_color;
  int cold_color;
//debuging help
  int last_waterflow_max1 = 0;
  int last_waterflow_max2 = 0;
  int last_waterflow_Min1 = 0;
  int last_waterflow_Min2 = 0;
  int last_warm_color = 0;
  int last_cold_color = 0;
//sensor min reading
  int run_min_read_sensors = 0;
//demo in
  int demopin = 5;
  int fadespeed = 100;
