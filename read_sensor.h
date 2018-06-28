void read_sensors()
{
  currentTime = millis();
  if(currentTime >= (cloopTime + 1000))
  {
    // Updates cloopTime
    cloopTime = currentTime;
    
    // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min. (Results in +/- 3% range)
    l_hour_1 = (flow_frequency_1 * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour
    l_hour_2 = (flow_frequency_2 * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour 
    
    waterflow_Max1=auto_calibrate(l_hour_1,waterflow_Max1,flow_frequency_1);
    waterflow_Max2=auto_calibrate(l_hour_2,waterflow_Max2,flow_frequency_2);
    
    flow_frequency_1= 0;
    flow_frequency_2= 0;
    
    if (last_waterflow_max1 != waterflow_Max1 or 
        last_waterflow_max2 != waterflow_Max2)
    { 
      
      Serial.print(waterflow_Max1);
      Serial.print(" || ");
      Serial.println(waterflow_Max2);
      
      last_waterflow_max1 = waterflow_Max1;
      last_waterflow_max2 = waterflow_Max2;
    }
  }
}
