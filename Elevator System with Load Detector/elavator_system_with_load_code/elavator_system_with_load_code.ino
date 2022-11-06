//By HomeMade Electronics
//Subscribe to my channel https://www.youtube.com/channel/UC8isJR_71x1wIfw6jB106pg
//for more tutorial videos
//like, share and leave a comment if you need help



#include "HX711.h"  //Get this library by clicking on Sketch>Include Library>Library Manager in the Arduino IDE and install it from there
#include<LiquidCrystal.h>
#define calibration_factor 18029.57 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define IN1 4
#define IN2 5
#define DOUT  3
#define CLK  2

#define Bstart 6
#define Bstop 7
float weight;
#define Bstopage 1
HX711 scale;
LiquidCrystal lcd(13,12,11,10,9,8);
void forward(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
}
void backward(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH); 
}

void stopage(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW); 
}

void setup() {
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
lcd.begin(16,2);

pinMode(Bstart,INPUT);
pinMode(Bstop,INPUT);
pinMode(Bstopage,INPUT);
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

}

void loop() {
weight=scale.get_units()/2;
lcd.setCursor(0,0);
lcd.print("WEIGHT MEASURED");
lcd.setCursor(6,1);
lcd.print(weight, 1); 
lcd.print(" Kg");
if (weight>60){
 stopage();
}
else{ 
if (digitalRead(Bstart)==LOW){
 forward();
}
}
reverse();
m_stopage();
}
// reverse movement of the motor function
void reverse(){
if (digitalRead(Bstop)==LOW){
if(weight>60)
stopage();
else
 backward();
}

}
void m_stopage(){
if (digitalRead(Bstopage)==LOW)
stopage();
}
