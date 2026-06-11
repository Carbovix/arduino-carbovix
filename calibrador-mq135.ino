#include <math.h>
#define MQ135 A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(MQ135);
  float Vrl = leitura * (5.0 / 1023.0);
  float Rsensor = (5.0 - Vrl) / Vrl;   // assumindo RL = 1 (proporcional)
  float R0 = Rsensor / 3.6;            // 3.6 = Rs/R0 típico em ar limpo p/ MQ-135

  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" | Vrl: ");
  Serial.print(Vrl, 3);
  Serial.print(" | Rsensor: ");
  Serial.print(Rsensor, 2);
  Serial.print(" | R0 calculado: ");
  Serial.println(R0, 2);

  delay(1000);
}