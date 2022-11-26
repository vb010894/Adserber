/*
 * ADC.c
 *
 * Библиотека для работы с аналогово цифрового преобразователя.
 *
 * Created: 19.11.2022 6:27:39
 *  Author: VladiBoy
 */ 
#define  F_CPU 10000000UL
#include <avr/io.h>

typedef struct adcConfig {
		int r1Val;
		int r2Val;
		double tranCof;
} adcConfig;

/// <summary>
/// Инициализация Аналогово-цифрового преобразователя.
/// </summary>
int ADC_init() {
	ADCSRA |= (1<<ADEN); // ВКЛЮЧАЕМ АЦП
	ADCSRA |= (1<<ADFR); // Включаем неприрывную работу
	ADCSRA &= ~(1<<ADPS2);
	ADCSRA |= (1<<ADPS1) | (1<<ADPS1); // 125 kHz
	ADMUX  |= (1<<REFS1) | (1<<REFS0); // 2.56V опорного.
	ADMUX  &= ~(1<<ADLAR); // Правосторонне выравнивание
	ADMUX  &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1)); // Выключаем АЦП выходы с 1 по 3 пин
	ADMUX  |= (1<<MUX0); // Аключаем первый АЦП (ADC1)
	ADCSRA |= (1<<ADSC); // Запускаем АЦП
	return 0;
}

/// <summary>
/// Получает значение преобразования.
/// </summary>
/// <param adcValue>Результат. Коэфициент ADC</param>
void ADC_Get(unsigned int *result) {
	if(ADCSRA & (1<<4)) {
		*result = ADC;		
		ADCSRA |= (1<<4);	
	}
	
	return 0;
}

/// <summary>
/// Преобразует ADC в значение постоянного напряжения.
/// </summary>
/// <param adcValue>Коэфициент ADC</param>
/// <param adcValue>Конфигурация ADC</param>
/// <param adcValue>Результат преобразования в постоянный ток</param>
void ADC_ToDC(unsigned int* adcValue, struct adcConfig* config, double* result) {
	int r1 = config->r1Val;
	int r2 = config->r2Val;
	double adcVolts = (*adcValue * 2.56) / 1024;
	double sum = (double) (r1 + r2);
	double rAll = (double) (r2 / sum); 
	*result = adcVolts / rAll;
}

/// <summary>
/// Преобразует ADC в значение переменного напряжения после трансформации.
/// </summary>
/// <param adcValue>Коэфициент ADC</param>
/// <param adcValue>Конфигурация ADC</param>
/// <param adcValue>Результат преобразования в переменное напряжение</param>
void ADC_ToAC(unsigned int* adc, adcConfig* config, unsigned int* result) {
	double vol = 0.0;
	ADC_ToDC(adc, config, &vol);
	*result = (int)  ((vol) * (config->tranCof));
}



