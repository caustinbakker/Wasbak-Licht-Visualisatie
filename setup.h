  void setup() 
  {
  Serial.begin(9600);
  Serial.print("Pre-Setup Compleet\n");
//in-built led is output-ing
  pinMode(LED_BUILTIN, OUTPUT);
//in-built led is low
  digitalWrite(LED_BUILTIN, LOW);
//RGB Output pin
  pinMode(warm_color, OUTPUT);
  pinMode(cold_color, OUTPUT);
//waterflow pin's
  pinMode(flowmeter_1, INPUT);
  pinMode(flowmeter_2, INPUT);
  attachInterrupt(0, flow_1, RISING); // Setup Interrupt 
  attachInterrupt(1, flow_2, RISING); // Setup Interrupt 
                                     // see http://arduino.cc/en/Reference/attachInterrupt
  sei();                            // Enable interrupts  
  Serial.println("Pinmodes Set");
  //demo pin
  pinMode(demopin, INPUT);
  Serial.println("Starting loop");
  }
