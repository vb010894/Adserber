/*
 * UART.h
 *
 * Created: 20.11.2022 4:29:37
 *  Author: VladiBoy
 */ 


#ifndef UART_H_
#define UART_H_

/// <summary>
/// �������������� UART.
/// �������� � �������� �� 1200 �����.
/// </summary>
int UART_init(void);


/// <summary>
/// �������� ������� � ����.
/// </summary>
/// <param adcValue>�������</param>
int UART_Send(char* cmd);

/// <summary>
/// �������� ������� � ����.
/// ������ FLOAT
/// </summary>
/// <param adcValue>�������</param>
int UART_SendFloat(float*);

/// <summary>
/// �������� ������� � ����.
/// ������ DOUABLE
/// </summary>
/// <param adcValue>�������</param>
int UART_SendDouble(double*);

/// <summary>
/// �������� ������� � ����.
/// ������ Int
/// </summary>
/// <param adcValue>�������</param>
int UART_SendInt(int*);



#endif /* UART_H_ */