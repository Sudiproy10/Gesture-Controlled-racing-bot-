#include<Wire.h>

#define accel_module (0x53)
byte values[6] ;
char output[512];

void setup(){
Wire.begin();
Serial.begin(9600);Wire.beginTransmission(accel_module);
Wire.write(0x2D);
Wire.write(0);
Wire.endTransmission();
Wire.beginTransmission(accel_module);
Wire.write(0x2D);
Wire.write(16);
Wire.endTransmission();

Wire.beginTransmission(accel_module);
Wire.write(0x2D);
Wire.write(8);
Wire.endTransmission();
pinMode(A5,INPUT);
pinMode(A4,INPUT);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);}
void loop(){
int xyzregister = 0x32;
int x, y;

Wire.beginTransmission(accel_module);
Wire.write(xyzregister);
Wire.endTransmission();

Wire.beginTransmission(accel_module);
Wire.requestFrom(accel_module, 6);

int i = 0;
while(Wire.available()){
values[i] = Wire.read();
i++;
}
x = (((int)values[1]) << 8) | values[0];
y = (((int)values[3])<< 8) | values[2];

sprintf(output, "%d %d", x, y);

Serial.print(output); Serial.write(10); delay(10);
 if(y<-120)
{digitalWrite(9,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(5,HIGH);      //bckwrd
   digitalWrite(3,LOW);
}  
 
  else if(y>120)
 {digitalWrite(9,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);      //frwrd
   digitalWrite(3,HIGH);
 }
 else if(x>120)
{digitalWrite(9,LOW);
   digitalWrite(6,LOW);
   digitalWrite(5,LOW);      //right
   digitalWrite(3,HIGH);
} 
   else if (x<-120)
{digitalWrite(9,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);      //lft
   digitalWrite(3,LOW);
}  else
   {
  digitalWrite(9,LOW);
   digitalWrite(6,LOW);
   digitalWrite(5,LOW);      //stp
   digitalWrite(3,LOW);
   }  } 
 
