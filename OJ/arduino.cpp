//烟雾+屏幕+粉尘+dht11
#include <MQ135.h>
#define Aout A1 //MQ-135 AO 接 Arduino Uno A0
MQ135 gasSensor = MQ135(ANALOGPIN);
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 8 //温湿度传感器接8号
#include <LCD5110_Basic.h>
const int ANALOGPIN=0;
LCD5110 myGLCD(3, 4, 5, 6, 7);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
int temp = 0; //临时变量，存储A0读取的数据
int temp1 = 0;//有害气体值temp1
float temp2 = 0;//粉尘浓度值temp2
int temp3 = 0;//湿度temp3
int temp4 = 0;//温度temp4
//led&&风扇&&蜂鸣器
int led1 = 10;//绿灯10
int led = 11;//黄灯11
int led2 = 12;//红灯12
int funpower = 13;//风扇供电引脚13
int beepower = 9;//蜂鸣器引脚9
//粉尘
int dustPin = 0;
float dustVal = 0;
int ledPower = 2;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;
void setup() {
  //风扇电力
  pinMode(funpower, OUTPUT);
  digitalWrite(funpower, HIGH);
  //蜂鸣器电力
  pinMode(beepower, OUTPUT);
  //led
  pinMode(led, OUTPUT); //使led亮起
  digitalWrite(led, HIGH);
  pinMode(led, OUTPUT); //使led亮起
  digitalWrite(led, HIGH);
  pinMode(led, OUTPUT); //使led亮起
  digitalWrite(led, HIGH);
  //
  Serial.begin(9600);//定义波特率
  pinMode(ledPower, OUTPUT);
  pinMode(dustPin, INPUT);

  pinMode(Aout, INPUT);//定义A1为INPUT模式
  myGLCD.InitLCD(); //Intializing LCD
  myGLCD.disableSleep();   //关闭休眠功能
}

void loop() {
  //有毒气体浓度值ppm
  float ppm = gasSensor.getPPM();
  //temp = analogRead(Aout); //读取A1的模拟数据
  temp = (int)ppm;
  temp1 = (int)temp;
  Serial.println(temp); //串口输出temp的数据
  delay(500);  //延时500毫秒
  myGLCD.setFont(SmallFont);
  myGLCD.print("toxic gas:", 0, 16);
  myGLCD.printNumI(temp1, RIGHT, 16);
  //delay(1000);
  //粉尘
  digitalWrite(ledPower, LOW);
  delayMicroseconds(delayTime);
  dustVal = analogRead(dustPin);
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(offTime);
  temp2 = (float(dustVal / 1024) - 0.0356) * 120000 * 0.035; //把粉尘传感器的值赋给temp2
  if ((temp2 > 1050)||(temp>600)) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1,LOW );
    digitalWrite(led, LOW);
    digitalWrite(beepower, HIGH); //高污染情况，红灯亮，蜂鸣器报警
    delay(500);
    digitalWrite(beepower,LOW);
    delay(200);
  }
  else if (temp2 >= 300 && temp2 <= 1050) {
    digitalWrite(led, HIGH); //中等空气质量，黄灯亮。
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else {
    digitalWrite(led1, HIGH); //绿灯亮
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
  }
  Serial.println((float(dustVal / 1024) - 0.0356) * 120000 * 0.035);
  myGLCD.print("dust:", 0, 36);
  myGLCD.printNumI((int)temp2, RIGHT, 36);
  //温湿度传感器代码
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
      Serial.println("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;
    default:
      Serial.println("Unknown error");
      break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  temp3 = (int)DHT11.humidity;//temp3为湿度
  temp4 = (int)DHT11.temperature;//temp4为温度
  myGLCD.print("T/H", 0, 6);
  myGLCD.printNumI(temp4, CENTER, 6);
  myGLCD.printNumI(temp3, RIGHT, 6);
  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);
}
