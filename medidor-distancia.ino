#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos do Ultrassônico
const int trigPin = 9;
const int echoPin = 10;

// Pinos dos LEDs e buzzer
const int ledVerde = 4;
const int ledAmarelo = 2;
const int ledVermelho = 1;
const int buzzer = 3;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("  SafePlace");
  lcd.setCursor(0, 1);
  lcd.print(" Monitorando...");
  delay(2000);
}

void loop() {
  long duracao;
  float distancia;

  // Envia sinal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leitura do echo
  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel:");

  // Avaliação do nível de água
  if (distancia > 20) { // Nível baixo (ajuste conforme a maquete)
    lcd.print(" Baixo");
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } else if (distancia <= 20 && distancia > 10) { // Nível médio
    lcd.print(" Medio");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, LOW);
  } else { // Nível alto - Perigo
    lcd.print(" PERIGO!");
    lcd.setCursor(0, 1);
    lcd.print("ALERTA ENCHENTE");
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(1000);
}
