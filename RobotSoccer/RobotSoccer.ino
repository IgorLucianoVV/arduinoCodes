#include "BluetoothSerial.h"
#include <Servo.h>
#define pin0 13
#define pin1 22
#define pin2 23
#define pin3 19
#define pin4 21
char comando;
BluetoothSerial SerialBT;

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("Carrinho 123");
  servoMotor.attach(pin0);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.println("Fim Setup");
  delay(2000);
}

void loop() {


  while (SerialBT.available() > 0) {
    comando = SerialBT.read();

    delay(10);

    switch (comando) {
      case 'F':
        {  //move frente
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, HIGH);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          break;
        }
      case 'I':
        {  //frente direita

          digitalWrite(pin1, LOW);
          digitalWrite(pin2, HIGH);

          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          break;
        }
      case 'G':
        {  //frente esquerda
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, LOW);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          break;
        }
      case 'R':
        {  //direita
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, LOW);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          break;
        }
      case 'L':
        {  //esquerda
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, HIGH);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          break;
        }
      case 'B':
        {  // ré
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, LOW);

          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, LOW);
          delay(20);

          break;
        }
      case 'H':
        {  // ré esquerda
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, HIGH);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);


          break;
        }
      case 'J':
        {  //ré direita
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, LOW);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, HIGH);
          break;
        }
      case 'W':
        {  //GOLLLLLL

          servoMotor.write(170);
          delay(500);
          servoMotor.write(20);
          

          break;
        }
      default:
        {
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, LOW);

          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          break;
        }
    }
  }
}
