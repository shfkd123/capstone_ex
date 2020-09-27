//#include "DHT.h"
#include <DHT11.h>
#define MO1PIN A1
#define MO2PIN A2
#define DHTPIN 7

DHT11 dht(DHTPIN);//습도센서 pin

//한번만 실행
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
 
}
//여러번 실행
void loop() {
  // put your main code here, to run repeatedly:
  /*
   * 블루투스 연결하기
   */

  
  //습도센서
  float h, t;
  int i = dht.read(h, t);// 습도를 측정합니다.
  
  //토양수분센서 pin연결
  int moisture = analogRead(MO1PIN);
  int moisture2 = analogRead(MO2PIN);
  
  Serial.print("토양수분센서 값1: ");
  Serial.println(moisture);
  delay(100);
  Serial.print("토양수분센서 값2: ");
  Serial.println(moisture2);
  delay(100);
  Serial.print("습도센서 값: ");
  Serial.println(h);
  delay(100);
    
  //토양수분센서값을 안드로이드에 전송
  //1전송한 다음에 delay 
  delay(300); //센서 값 혼란 생각
  //2전송한 다음에 delay
  delay(300);
  //습도값을 안드로이드에 전송
  delay(300);

  
}
