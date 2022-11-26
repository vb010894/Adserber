/*
 * ADC.h
 *
 * Created: 19.11.2022 6:30:51
 *  Author: VladiBoy
 */ 


#ifndef ADC_H_
/*
 * ADC.h
 *
 * ������������� ���� ������ � ��������� ��������� ���������������.
 *
 * Created: 19.11.2022 6:27:39
 *  Author: VladiBoy
 */ 
#define ADC_H_

struct adcConfig {
	int r1Val;
	int r2Val;
	double tranCof;
};

/// <summary>
/// ������������� ���������-��������� ���������������.
/// </summary>
int ADC_init(void);

/// <summary>
/// �������� �������� ��������������.
/// </summary>
/// <param adcValue>���������. ���������� ADC</param>
int ADC_Get(unsigned int*);

/// <summary>
/// ����������� ADC � �������� ����������� ����������.
/// </summary>
/// <param adcValue>���������� ADC</param>
/// <param adcValue>������������ ADC</param>
/// <param adcValue>��������� �������������� � ���������� ���</param>
double ADC_ToDC(unsigned int*, struct adcConfig*, double*);

/// <summary>
/// ����������� ADC � �������� ����������� ���������� ����� �������������.
/// </summary>
/// <param adcValue>���������� ADC</param>
/// <param adcValue>������������ ADC</param>
/// <param adcValue>��������� �������������� � ���������� ����������</param>
int ADC_ToAC(unsigned int* vol, struct adcConfig*, unsigned int*);

#endif /* ADC_H_ */