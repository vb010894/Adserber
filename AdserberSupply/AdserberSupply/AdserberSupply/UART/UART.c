/*
 * UART.c
 *
 * Created: 20.11.2022 4:29:23
 *  Author: VladiBoy
 */ 

#define  F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>

/// <summary>
/// �������������� UART.
/// �������� � �������� �� 1200 �����.
/// </summary>
int UART_init() {
	UCSRB|=(1<<3)|(1<<4);
	UBRRH=0x00;
	UBRRL=0x34;
	
	return 0;
}

/// <summary>
/// �������� ������� � ����.
/// </summary>
/// <param adcValue>�������</param>
int UART_Send(char* cmd) {
	for(int i = 0; i < strlen(cmd); i++) {
		while(!(UCSRA & (1<<5))) {}
		UDR = cmd[i];
	}
	UDR = "\r";
		
	return 0;
}

/// <summary>
/// �������� ������� � ����.
/// ������ FLOAT
/// </summary>
/// <param adcValue>�������</param>
int UART_SendFloat(float* cmd) {
	char buffer[5];
	sprintf(buffer, "%f \n", *cmd);
	UART_Send(buffer);
	
	return 0;
}

/// <summary>
/// �������� ������� � ����.
/// ������ DOUABLE
/// </summary>
/// <param adcValue>�������</param>
int UART_SendDouble(double *cmd) {
	char buffer[50];
	sprintf(buffer, "%f \n", *cmd);
	UART_Send(buffer);
	return 0;
}

/// <summary>
/// �������� ������� � ����.
/// ������ Int
/// </summary>
/// <param adcValue>�������</param>
int UART_SendInt(int* cmd) {
	char buffer[50];
	sprintf(buffer, "%d \n", *cmd);
	UART_Send(buffer);
	
	return 0;
}

