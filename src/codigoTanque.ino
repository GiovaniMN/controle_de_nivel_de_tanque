#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

#define col 16
#define lin  2
#define ende  0x27

#define pino_trigger A3
#define pino_echo A2
#define pino_bomba 0

LiquidCrystal_I2C lcd(ende, col, lin);
Ultrasonic ultrasonic(pino_trigger, pino_echo);

int porcentagem = 80;

const float altura_max = 25.0;
const float altura_min = 4.0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(pino_bomba, OUTPUT);
  digitalWrite(pino_bomba, LOW);

  if (porcentagem >= 0 && porcentagem <= 100) {
    float altura_desejada = map(porcentagem, 0, 100, altura_max, altura_min);
    encherTanque(altura_desejada);
  }
}

void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  float nivel_porcentagem = ((altura_max - cmMsec) / (altura_max - altura_min)) * 100.0;
  nivel_porcentagem = constrain(nivel_porcentagem, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Nivel do tanque:");
  lcd.setCursor(0, 1);
  lcd.print(nivel_porcentagem);
  lcd.print(" %");

  controlarBomba(cmMsec);

  delay(500);
}

void encherTanque(float altura_desejada) {
  controlarBomba(altura_desejada);
}

void controlarBomba(float cmMsec) {
  float altura_desejada = map(porcentagem, 0, 100, altura_max, altura_min);

  if (cmMsec <= altura_desejada) {
    digitalWrite(pino_bomba, LOW);
  } else {
    digitalWrite(pino_bomba, HIGH);
  }
}
