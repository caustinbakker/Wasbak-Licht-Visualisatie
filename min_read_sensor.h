void min_read_sensors()
{
  while (run_min_read_sensors != 5)
  {
    currentTime = millis();
    if(currentTime >= (cloopTime + 1000))
    {
      // Updates cloopTime
      cloopTime = currentTime;
      
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
      l_hour_1 = (flow_frequency_1 * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour
      l_hour_2 = (flow_frequency_2 * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 
      
      waterflow_Min1=auto_calibrate(l_hour_1,waterflow_Min1,flow_frequency_1);
      waterflow_Min2=auto_calibrate(l_hour_2,waterflow_Min2,flow_frequency_2);
      
      flow_frequency_1= 0;
      flow_frequency_2= 0;
      
      if (last_waterflow_Min1 != waterflow_Min1 or 
          last_waterflow_Min2 != waterflow_Min2)
      { 
        Serial.println("Waterflow Min Values");
        Serial.print(waterflow_Min1);
        Serial.print(" || ");
        Serial.println(waterflow_Min2);
        
        last_waterflow_Min1 = waterflow_Min1;
        last_waterflow_Min2 = waterflow_Min2;
      }
      //run color changing randomly
      analogWrite(warm_color_pin, 255);
      analogWrite(cold_color_pin, 255);
      delay(100);   
    }
    //set colors to 0
    analogWrite(warm_color_pin, 0);
    analogWrite(cold_color_pin, 0);
    run_min_read_sensors++;
    if (run_min_read_sensors == 5)
    {
      Serial.println("Min read sensor Set");
      if (waterflow_Min1 or waterflow_Min2 != 0) 
      {
        Serial.println(waterflow_Min1);
        Serial.println(waterflow_Min2);
      }
    }
  }
}
