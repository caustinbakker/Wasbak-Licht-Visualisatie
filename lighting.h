int lighting(int endlight,int currentlight,int speed)
  {
  if (endlight < currentlight)
  {
  endlight=endlight+speed;
  }
  else if (endlight > currentlight)
  {
  endlight=endlight-speed;
  }
  return endlight;
  delay(100);
  }
