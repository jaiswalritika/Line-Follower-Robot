
#include "alphabot_drivers.h"
#include "line_follower.h"
#include <Wire.h>
 
#define IRSensor 9

#define Addr  0x20

#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem self;

unsigned long previousMillis = 0;
const long interval = 500;
int second = 0;
int beacon = 0;

void setup()
{
  init_devices();
  forward();
  Serial.begin(115200);
  Wire.begin();
  // port_expander_init();

  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop()
{
  unsigned long currentMillis = millis(); 

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 
    second = second + 1;
    beacon = 1;
  }
  else {
    beacon = 0;
  }

  int frontDetection = -1;
    char result = ir_read();
 
    switch (result) {
        case 'b':
            frontDetection = 2;
            break;
        case 'l':
            frontDetection = 0;
            break;
        case 'r':
            frontDetection = 1;
            break;
        default:
            frontDetection = -1;
            break;
    }


  AnalogRead(sensorValues);
  int leftforwardDetection = digitalRead(4);
  int leftbackwardDetection = digitalRead(8);
  int rightforwardDetection = digitalRead(7);
  int rightbackwardDetection = digitalRead(9);

 

  Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], frontDetection, leftforwardDetection, leftbackwardDetection, rightforwardDetection, rightbackwardDetection, beacon, second, &_res,&self);
  // Serial.print(_res.v_l);
  // Serial.print(" ");
  // Serial.print(_res.v_r);
  // Serial.print(" Current Counter Value: ");
  // Serial.print(_res.cnt);
  // Serial.print(" ");
  // Serial.println(_res.dir);

  Serial.println(leftforwardDetection);
  
 if(_res.dir==4){
   left();
   delay(5);
 }
 else if(_res.dir==5){
   right();
 }
 else if(_res.dir==6){
    backward();
 }
 else
   forward();
 
   
  SetSpeed(_res.v_l, _res.v_r);

  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print(' ');
  }
  
  Serial.println();
}
