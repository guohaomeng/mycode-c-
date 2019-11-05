//����+��Ļ+�۳�+dht11
#include <MQ135.h>
#define Aout A1 //MQ-135 AO �� Arduino Uno A0
MQ135 gasSensor = MQ135(ANALOGPIN);
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 8 //��ʪ�ȴ�������8��
#include <LCD5110_Basic.h>
const int ANALOGPIN=0;
LCD5110 myGLCD(3, 4, 5, 6, 7);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
int temp = 0; //��ʱ�������洢A0��ȡ������
int temp1 = 0;//�к�����ֵtemp1
float temp2 = 0;//�۳�Ũ��ֵtemp2
int temp3 = 0;//ʪ��temp3
int temp4 = 0;//�¶�temp4
//led&&����&&������
int led1 = 10;//�̵�10
int led = 11;//�Ƶ�11
int led2 = 12;//���12
int funpower = 13;//���ȹ�������13
int beepower = 9;//����������9
//�۳�
int dustPin = 0;
float dustVal = 0;
int ledPower = 2;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;
void setup() {
  //���ȵ���
  pinMode(funpower, OUTPUT);
  digitalWrite(funpower, HIGH);
  //����������
  pinMode(beepower, OUTPUT);
  //led
  pinMode(led, OUTPUT); //ʹled����
  digitalWrite(led, HIGH);
  pinMode(led, OUTPUT); //ʹled����
  digitalWrite(led, HIGH);
  pinMode(led, OUTPUT); //ʹled����
  digitalWrite(led, HIGH);
  //
  Serial.begin(9600);//���岨����
  pinMode(ledPower, OUTPUT);
  pinMode(dustPin, INPUT);

  pinMode(Aout, INPUT);//����A1ΪINPUTģʽ
  myGLCD.InitLCD(); //Intializing LCD
  myGLCD.disableSleep();   //�ر����߹���
}

void loop() {
  //�ж�����Ũ��ֵppm
  float ppm = gasSensor.getPPM();
  //temp = analogRead(Aout); //��ȡA1��ģ������
  temp = (int)ppm;
  temp1 = (int)temp;
  Serial.println(temp); //�������temp������
  delay(500);  //��ʱ500����
  myGLCD.setFont(SmallFont);
  myGLCD.print("toxic gas:", 0, 16);
  myGLCD.printNumI(temp1, RIGHT, 16);
  //delay(1000);
  //�۳�
  digitalWrite(ledPower, LOW);
  delayMicroseconds(delayTime);
  dustVal = analogRead(dustPin);
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(offTime);
  temp2 = (float(dustVal / 1024) - 0.0356) * 120000 * 0.035; //�ѷ۳���������ֵ����temp2
  if ((temp2 > 1050)||(temp>600)) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1,LOW );
    digitalWrite(led, LOW);
    digitalWrite(beepower, HIGH); //����Ⱦ����������������������
    delay(500);
    digitalWrite(beepower,LOW);
    delay(200);
  }
  else if (temp2 >= 300 && temp2 <= 1050) {
    digitalWrite(led, HIGH); //�еȿ����������Ƶ�����
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else {
    digitalWrite(led1, HIGH); //�̵���
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
  }
  Serial.println((float(dustVal / 1024) - 0.0356) * 120000 * 0.035);
  myGLCD.print("dust:", 0, 36);
  myGLCD.printNumI((int)temp2, RIGHT, 36);
  //��ʪ�ȴ���������
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
  temp3 = (int)DHT11.humidity;//temp3Ϊʪ��
  temp4 = (int)DHT11.temperature;//temp4Ϊ�¶�
  myGLCD.print("T/H", 0, 6);
  myGLCD.printNumI(temp4, CENTER, 6);
  myGLCD.printNumI(temp3, RIGHT, 6);
  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);
}
