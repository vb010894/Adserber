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
 * Заголовочныый файл работы с аналогово цифрового преобразователя.
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
/// Инициализация Аналогово-цифрового преобразователя.
/// </summary>
int ADC_init(void);

/// <summary>
/// Получает значение преобразования.
/// </summary>
/// <param adcValue>Результат. Коэфициент ADC</param>
int ADC_Get(unsigned int*);

/// <summary>
/// Преобразует ADC в значение постоянного напряжения.
/// </summary>
/// <param adcValue>Коэфициент ADC</param>
/// <param adcValue>Конфигурация ADC</param>
/// <param adcValue>Результат преобразования в постоянный ток</param>
double ADC_ToDC(unsigned int*, struct adcConfig*, double*);

/// <summary>
/// Преобразует ADC в значение переменного напряжения после трансформации.
/// </summary>
/// <param adcValue>Коэфициент ADC</param>
/// <param adcValue>Конфигурация ADC</param>
/// <param adcValue>Результат преобразования в переменное напряжение</param>
int ADC_ToAC(unsigned int* vol, struct adcConfig*, unsigned int*);

#endif /* ADC_H_ */