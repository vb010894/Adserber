/*
 * ADC.c
 *
 * ���������� ��� ������ � ��������� ��������� ���������������.
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
/// ������������� ���������-��������� ���������������.
/// </summary>
int ADC_init() {
	ADCSRA |= (1<<ADEN); // �������� ���
	ADCSRA |= (1<<ADFR); // �������� ����������� ������
	ADCSRA &= ~(1<<ADPS2);
	ADCSRA |= (1<<ADPS1) | (1<<ADPS1); // 125 kHz
	ADMUX  |= (1<<REFS1) | (1<<REFS0); // 2.56V ��������.
	ADMUX  &= ~(1<<ADLAR); // ������������� ������������
	ADMUX  &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1)); // ��������� ��� ������ � 1 �� 3 ���
	ADMUX  |= (1<<MUX0); // �������� ������ ��� (ADC1)
	ADCSRA |= (1<<ADSC); // ��������� ���
	return 0;
}

/// <summary>
/// �������� �������� ��������������.
/// </summary>
/// <param adcValue>���������. ���������� ADC</param>
void ADC_Get(unsigned int *result) {
	if(ADCSRA & (1<<4)) {
		*result = ADC;		
		ADCSRA |= (1<<4);	
	}
	
	return 0;
}

/// <summary>
/// ����������� ADC � �������� ����������� ����������.
/// </summary>
/// <param adcValue>���������� ADC</param>
/// <param adcValue>������������ ADC</param>
/// <param adcValue>��������� �������������� � ���������� ���</param>
void ADC_ToDC(unsigned int* adcValue, struct adcConfig* config, double* result) {
	int r1 = config->r1Val;
	int r2 = config->r2Val;
	double adcVolts = (*adcValue * 2.56) / 1024;
	double sum = (double) (r1 + r2);
	double rAll = (double) (r2 / sum); 
	*result = adcVolts / rAll;
}

/// <summary>
/// ����������� ADC � �������� ����������� ���������� ����� �������������.
/// </summary>
/// <param adcValue>���������� ADC</param>
/// <param adcValue>������������ ADC</param>
/// <param adcValue>��������� �������������� � ���������� ����������</param>
void ADC_ToAC(unsigned int* adc, adcConfig* config, unsigned int* result) {
	double vol = 0.0;
	ADC_ToDC(adc, config, &vol);
	*result = (int)  ((vol) * (config->tranCof));
}



