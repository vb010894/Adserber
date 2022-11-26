/*
 * main.h
 *
 * Created: 21.11.2022 1:44:24
 *  Author: VladiBoy
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define  F_CPU 10000000UL // Частота контроллера

/// Стандартные библиотеки
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "ADC/ADC.h" // Аналогово-цифровой преобразователь 
#include "UART/UART.h" // UART шина

#define INDECATION_INI DDRB = 0b11100000 // Инициализация индикации напряжения

#define GREEN_ON PORTB |= (1<<6) // Включение зеленого сигнала
#define GREEN_OFF PORTB &= ~(1<<6) // Выключение зеленого сигнала
#define RED_ON PORTB |= (1<<7) // Включение красного сигнала
#define RED_OFF PORTB  &= ~(1<<7) // Выключение красного сигнала

#define POWER_OK_ON PORTB |= (1<<5) // Включение сигнала стабильного питания
#define POWER_OK_OFF PORTB &= ~(1<<5) // Выключение сигнала стабильного питания

void setup(void);

#endif /* MAIN_H_ */