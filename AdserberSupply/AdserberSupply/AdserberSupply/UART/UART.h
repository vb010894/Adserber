/*
 * UART.h
 *
 * Created: 20.11.2022 4:29:37
 *  Author: VladiBoy
 */ 


#ifndef UART_H_
#define UART_H_

/// <summary>
/// Инициализирует UART.
/// Работает в протеусе на 1200 бодах.
/// </summary>
int UART_init(void);


/// <summary>
/// Посылает команду в шину.
/// </summary>
/// <param adcValue>Команда</param>
int UART_Send(char* cmd);

/// <summary>
/// Посылает команду в шину.
/// Формат FLOAT
/// </summary>
/// <param adcValue>Команда</param>
int UART_SendFloat(float*);

/// <summary>
/// Посылает команду в шину.
/// Формат DOUABLE
/// </summary>
/// <param adcValue>Команда</param>
int UART_SendDouble(double*);

/// <summary>
/// Посылает команду в шину.
/// Формат Int
/// </summary>
/// <param adcValue>Команда</param>
int UART_SendInt(int*);



#endif /* UART_H_ */