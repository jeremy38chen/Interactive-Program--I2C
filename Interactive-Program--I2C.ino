#include<Wire.h>
#define I2CADDR 0x60
const PROGMEM int FullSine[32]=
{
    2048,2447,2831,3185,3495,3750,3939,4056,4095,3939,3750,3495,3185,2831,2447,2048,1648,1264,910,600,345,156,39,0,39,156,345,600,910,1264,1648
};
void setup() {
  // put your setup code here, to run once:
}

void setVoltage(int output) {
  // put your main code here, to run repeatedly:
  char twbc =TWBR;
  TWBR =((F_CPU/400000L)-16)/2;
  Wire.beginTransmission(I2CADDR);
  Wire.write(0x40);
  Wire.write(output/16);
  Wire.write((output%16)<<4);
  Wire.endTransmission();
  TWBR = twbc;
}

void loop(){

  for(int i=0;i<32;i++){

    setVoltage(pgm_read_word(&(FullSine[i])));
    delay(analogRead(A0)/4);
  }


}

