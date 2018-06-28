int cold_color_up()
{
  for (cold_color = 0; cold_color < 256; cold_color++) 
  { 
  analogWrite(cold_color_pin, cold_color);
  delay(fadespeed);
  }
}

int cold_color_down()
{
    for (cold_color = 255; cold_color > 0; cold_color--)
    {
      analogWrite(cold_color_pin, cold_color);
      delay(fadespeed);
    }
}

int warm_color_up()
{
  for (warm_color = 0; warm_color < 256; warm_color++) 
    { 
    analogWrite(warm_color_pin, warm_color);
    delay(fadespeed);
    }
}

int warm_color_down()
{
  for (warm_color = 255; warm_color > 0; warm_color--) 
    { 
    analogWrite(warm_color_pin, warm_color);
    delay(fadespeed);
    }
}
