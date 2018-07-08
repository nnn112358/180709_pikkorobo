#include <Servo.h>

Servo mot[4];

void setup() {
Serial.begin(9600);
  mot[0].attach(4);
  mot[1].attach(5);
  mot[2].attach(6);
  mot[3].attach(7);

  mot[0].write(90);
  mot[1].write(90);
  mot[2].write(90);
  mot[3].write(90);
}

void loop() {
  if ( Serial.available() > 0 ) {
    String str = Serial.readStringUntil('\n');
    Serial.println(str);
    int num=0;
    int degree=0;
    sscanf( str.c_str(), "%d %d", &num, &degree);
    Serial.print(num);
    Serial.print("_");
    Serial.print(degree);
    Serial.print("\n");

    if(degree<60)degree=60;
    if(degree>120)degree=120;
    
    mot[num].write(degree);
//    mot[1].write(90);
//    mot[2].write(90);
//    mot[3].write(90);

  }



}


