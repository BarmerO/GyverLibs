#include <directADC.h>
void setup() {
  Serial.begin(9600);
  ACOMP_attachInterrupt(func, FALLING_TRIGGER); // прерывание как только напряжение на -in превысит напряжение на +in
  ADC_disable(); // если используем мультиплексор для компаратора - обяательно выключаем ацп
  ACOMP_setPositiveInput(ADC_1V1); // подключить +in к 1.1В
  ACOMP_setNegativeInput(ANALOG_MUX); // подключить -in к аналоговому мультиплексору (ацп должен быть выключен!);
  /* если в таком режиме включить АЦП , -in компаратора переключится на ADC_AIN1 - pin 7 , до того момента, пока ацп опять не выключится */
  setAnalogMux(ADC_A2); // -in компаратора будет отслеживать вывод ADC_A2
}

void func() { // как только напряжение на входе А2 превысит 1.1В произойдет прерывание
  Serial.println("isr");
}

void loop() {
}
/* прерывание происходит ТОЛЬКО в момент перехода выхода компаратора из одного положения в другое */