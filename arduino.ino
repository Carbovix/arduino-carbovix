// CARBOVIX v.1 - Monitor de qualidade do ar com MQ-135
// LCD I2C: SDA → A4, SCL → A5
// MQ-135: A0
// LED: pino 6
// BUZZER: pino 7

#include <Wire.h>
#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define MQ135         A0
#define LED           6
#define BUZZER        7
float R0 = 70.62;      // Valor calibrado!
#define LIMITE_BUZZER 1500

float calcularPPM(int valorADC) {
  float Vrl = valorADC * (5.0 / 1023.0);
  if (Vrl <= 0.01) return 0;
  float Rsensor = (5.0 - Vrl) / Vrl * R0;
  float ratio   = Rsensor / R0;
  float ppm     = 116.6020682 * pow(ratio, -2.769034857);
  return ppm;
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  noTone(BUZZER);
  digitalWrite(LED, LOW);

  lcd.setCursor(0, 0);
  lcd.print("CARBOVIX v.1");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  delay(3000);
  lcd.clear();

  Serial.println("Sis_iniciado!");
}
void loop() {

  int leitura = analogRead(MQ135);
  float ppm   = calcularPPM(leitura);

  Serial.print("PPM: ");
  Serial.println(ppm);

  lcd.setCursor(0, 0);
  lcd.print("Qualidade Ar    ");
  lcd.setCursor(0, 1);
  lcd.print("PPM:");
  lcd.setCursor(5, 1);
  lcd.print(ppm, 1);
  lcd.print("    ");

  // LED liga sempre que detectar gás
  if (ppm > 0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  // Buzzer só apita acima de 1500 PPM
  if (ppm > LIMITE_BUZZER) {
    tone(BUZZER, 1000);
    lcd.setCursor(0, 0);
    lcd.print("!! ALERTA GAS !!");
    Serial.println("ALERTA! GAS ALTO!");
  } else {
    noTone(BUZZER);
  }
  delay(2000);
}