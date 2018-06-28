int auto_calibrate(int sensor_value,int sensor_max_value, int flow_frequency)
{
  
  if (sensor_value > sensor_max_value) 
    {
    
    sensor_max_value = sensor_value;
    int sensor_change = sensor_value-sensor_max_value;
    }
  return sensor_max_value;
}
