#include <Servo.h> 
 
//Create the 4 esc objects
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;
 
//Esc pins
int escPin1 = 8;
int escPin2 = 9;
int escPin3 = 10;
int escPin4 = 11;

//Min and max pulse
int minPulseRate        = 1000;
int maxPulseRate        = 2000;
int throttleChangeDelay = 50;

if (Serial.available(char a =  Serial.read ()){
  if (a== '1')
  print ("one");
 int normalizeThrottle(int value) {
  if(value < 0) {
    return 0;
    
  } else if(value > 180) {
    return 180;
  }
 }
  return value;
//SETUP
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
  
  //Init escs
  initEscs();
}


 
//LOOP
void loop() {
  // Wait for some input
  if (Serial.available() > 0) {
    
    // Read the new throttle value
    int throttle = normalizeThrottle(Serial.parseInt());
    
    // Print it out
    Serial.print("Setting throttle to: ");
    Serial.println(throttle);
    
    // Change throttle to the new value
    changeThrottle(throttle);
  }
 
}
 
//Change throttle value
void changeThrottle(int throttle) {
  int currentThrottle = readThrottle();
  
  int step = 1;
  if(throttle < currentThrottle) {
    step = -1;
  }
  
  // Slowly move to the new throttle value 
  while(currentThrottle != throttle) {
    writeTo4Escs(currentThrottle + step);
    
    currentThrottle = readThrottle();
    delay(throttleChangeDelay);
  }
}

//Read the throttle value
int readThrottle() {
  int throttle = esc1.read();
  
  Serial.print("Current throttle is: ");
  Serial.print(throttle);
  Serial.println();
  
  return throttle;
}

//Change velocity of the 4 escs at the same time
void writeTo4Escs(int throttle) {
  esc1.write(throttle);
  esc2.write(throttle);
  esc3.write(throttle);
  esc4.write(throttle);
}

//Init escs
void initEscs() {
  esc1.attach(escPin1, minPulseRate, maxPulseRate);
  esc2.attach(escPin2, minPulseRate, maxPulseRate);
  esc3.attach(escPin3, minPulseRate, maxPulseRate);
  esc4.attach(escPin4, minPulseRate, maxPulseRate);
  
  //Init motors with 0 value
  writeTo4Escs(0);
}

//Start the motors
void startUpMotors() {
  writeTo4Escs(50);
}
 
// Ensure the throttle value is between 0 - 180
int normalizeThrottle(int value) {
  if(value < 0) {
    return 0;
    
  } else if(value > 180) {
    return 180;
  }
  
  return value;
}
