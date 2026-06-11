// CARBOVIX v.1 - Monitor de qualidade do ar com MQ-135
// LCD I2C: SDA → A4, SCL → A5
// MQ-135: A0
// LED: pino 6
// BUZZER: pino 7

#include <Wire.h>
#include <math.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);