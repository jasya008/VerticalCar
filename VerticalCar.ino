#include <Wire.h>

// Пины для моторов
const int IN1 = PA0; 
const int IN2 = PA1;
const int IN3 = PA2;
const int IN4 = PA3;
const int ENA = PA6; // Пин для регулировки скорости левого мотора
const int ENB = PA7; // Пин для регулировки скорости правого мотора

// РЕГУЛИРОВКА СКОРОСТИ (напряжения)
// 0 - стоим, 255 - максимум (около 7-8 вольт от аккумуляторов)
int motorSpeed = 1000; 

void setup() {
  // Настраиваем все пины на выход
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Запускаем моторы один раз при старте
  moveForward(motorSpeed);
}

void loop() {
  // Пусто: машинка будет ехать постоянно с заданной скоростью
}

void moveForward(int speed) {
  // Направление для левого мотора
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed); // Регулировка напряжения через ШИМ

  // Направление для правого мотора
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed); // Регулировка напряжения через ШИМ
}