#include <Servo.h>

Servo mine;//设置舵机对象

int pos = 0;//创建角度变量

void setup() {
 Serial.begin(9600);
 mine.attach(6);//将舵机连接到引脚
}

void loop() {
 pos = 0; 
 mine.write(pos);
 delay(500);

 pos = 30;
 mine.write(pos);
 delay(500);

 pos = 45;
 mine.write(pos);
 delay(500);

 pos = 90;
 mine.write(pos);
 delay(500);

 pos = 135;
 mine.write(pos);
 delay(500);//舵机依次转动到对应角度
}
