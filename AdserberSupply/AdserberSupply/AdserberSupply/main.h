/*
 * main.h
 *
 * Created: 21.11.2022 1:44:24
 *  Author: VladiBoy
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define  F_CPU 10000000UL // ������� �����������

/// ����������� ����������
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "ADC/ADC.h" // ���������-�������� ��������������� 
#include "UART/UART.h" // UART ����

#define INDECATION_INI DDRB = 0b11100000 // ������������� ��������� ����������

#define GREEN_ON PORTB |= (1<<6) // ��������� �������� �������
#define GREEN_OFF PORTB &= ~(1<<6) // ���������� �������� �������
#define RED_ON PORTB |= (1<<7) // ��������� �������� �������
#define RED_OFF PORTB  &= ~(1<<7) // ���������� �������� �������

#define POWER_OK_ON PORTB |= (1<<5) // ��������� ������� ����������� �������
#define POWER_OK_OFF PORTB &= ~(1<<5) // ���������� ������� ����������� �������

void setup(void);

#endif /* MAIN_H_ */