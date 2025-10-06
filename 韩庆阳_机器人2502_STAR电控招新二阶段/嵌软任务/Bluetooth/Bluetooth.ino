#include <SoftwareSerial.h>
#include <Servo.h>//调用两个库文件

SoftwareSerial BTserial(8,9);//将蓝牙连接到引脚8，9
Servo mine;//设置舵机对象

int pos = 0;
void setup() {
 Serial.begin(9600);
 BTserial.begin(9600);
 mine.attach(6);//将舵机连接到引脚6（PWM）
}

void loop() {
static String Data = "";//创建字符串变量Data（感谢豆包告诉我static String）
 if(BTserial.available()) {//蓝牙接收到数据后开始执行
  char c = BTserial.read();
  if(c =='\n'){//将转行作为结束符
  pos = Data.toInt();//将字符串转为整数
  pos = constrain(pos, 0, 180);//限定pos范围
  mine.write(pos);
  Serial.print("舵机转动到：");
  Serial.println(pos);//串口监视器监测转动状况
  Data = "";//将Data归零
  }
  else {
   Data = Data + c;//将收到的字符累加为字符串（这一步半天没弄出来，123°总是变成1°2°3°）
  }
 }
}