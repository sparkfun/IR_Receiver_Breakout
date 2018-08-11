/*
  SparkFun Electronics 2013
  Playing with Infrared Remote Control
  
  IR Receiver Breakout (SEN-8554): Supply voltage of 2.5V to 5.5V
    Attach
    OUT: To pin 11 on Arduino
    GND: GND
    VCC: 5V
  
  This is based on Ken Shirriff's code found on GitHub:
  https://github.com/shirriff/Arduino-IRremote/

  This code works with cheap remotes. If you want to look at the individual timing
  of the bits, use this code:
  http://www.arduino.cc/playground/Code/InfraredReceivers
*/

#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define POWER 0x10EFD827 
#define A 0x10EFF807 
#define B 0x10EF7887
#define C 0x10EF58A7
#define UP 0x10EFA05F
#define DOWN 0x10EF00FF
#define LEFT 0x10EF10EF
#define RIGHT 0x10EF807F
#define SELECT 0x10EF20DF

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    if (results.value == POWER) 
    {
      Serial.println("POWER");    
    }
     if (results.value == A) 
    {
      Serial.println("A");    
    }
     if (results.value == B) 
    {
      Serial.println("B");  
    }
     if (results.value == C) 
    {
      Serial.println("C");
    }
     if (results.value == UP) 
    {
      Serial.println("UP");
    }
     if (results.value == DOWN) 
    {
      Serial.println("DOWN");
    }
     if (results.value == LEFT) 
    {
      Serial.println("LEFT");
    }
     if (results.value == RIGHT) 
    {
      Serial.println("RIGHT");
    }
     if (results.value == SELECT) 
    {
      Serial.println("SELECT");  
    }
    irrecv.resume();
  }
}
