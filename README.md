# arduino-carbovix

Monitor de PPM utilizando sensor **MQ-135**, com exibição em display **LCD I2C** e alertas visuais/sonoros.

## Ligações

| Componente | Pino |
|------------|------|
| LCD I2C SDA | A4 |
| LCD I2C SCL | A5 |
| MQ-135 | A0 |
| LED | 6 |
| Buzzer | 7 |

## Funcionamento

- Lê o valor analógico do MQ-135 e calcula a concentração em **PPM**.
- Exibe a leitura no LCD e no Serial Monitor.
- **LED** acende sempre que detectar gás (PPM > 0).
- **Buzzer** dispara alerta sonoro/visual quando PPM ultrapassa **1500**.

## Calibração (R0)

O sketch `calibrador-mq135.ino` auxilia no cálculo do valor de **R0** do sensor, que deve ser medido em ambiente de ar limpo. Após obter o valor, atualize a constante `R0` no código principal.

## Bibliotecas necessárias

- [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C)
- `Wire.h` (nativa)
- `math.h` (nativa)

## Como usar

1. Conecte os componentes conforme a tabela acima.
2. Rode `calibrador-mq135.ino` em ambiente de ar limpo e anote o valor de R0.
3. Atualize a constante `R0` em `arduino.ino`.
4. Faça o upload do `arduino.ino` para o Arduino.
5. Acompanhe as leituras pelo LCD ou Serial Monitor (9600 baud).

---
