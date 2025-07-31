#include "alphabot_drivers.h"
#include "line_follower.h"

#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem self;

void setup()
{
  init_devices();
  forward();
  Serial.begin(115200);
}

void loop()
{
  AnalogRead(sensorValues);
  Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], &_res,&self);
  Serial.print(_res.v_l);
  Serial.print(" ");
  Serial.println(_res.v_r);
  Serial.print(" ");
  Serial.print(_res.dir);
  
  if(_res.dir==4){
   left();
   delay(5);
 }
 
 else if(_res.dir==5){
   right();
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
  // delay(1000);
}
