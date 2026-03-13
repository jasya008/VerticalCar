#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

const int IN1 = 0; const int IN2 = 1;
const int IN3 = 2; const int IN4 = 3;
const int ENA = 4; const int ENB = 5;

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);

  Serial.println("--- START TEST ---");
  
  Wire.begin(8, 9);
  // Пробуем запустить гироскоп, но не ждем его вечно
  if (!mpu.begin()) {
    Serial.println("MPU6050 NOT FOUND - Running in manual mode");
  } else {
    Serial.println("MPU6050 OK!");
  }
}

void loop() {
  // Тестовый цикл: 1 секунда вперед, 1 секунда назад
  Serial.println("Forward...");
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); analogWrite(ENB, 255);
  delay(500);

  Serial.println("Backward...");
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(500);
}