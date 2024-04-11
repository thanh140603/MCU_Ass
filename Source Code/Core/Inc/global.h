/*
 * global.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include<stdio.h>
#include<main.h>
#include "button.h"
#include "main.h"
#include "software_timer.h"
#include "scheduler.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"


#define INIT			1
#define RED_GREEN		2
#define RED_YELLOW		3
#define GREEN_RED		4
#define YELLOW_RED		5

#define MAN_RED			13
#define MAN_YELLOW		14
#define MAN_GREEN		15

extern int status;
extern int index_led;
extern int horizontal_number;
extern int vertical_number;

void countDown();
void setInitialValue(int horizontal, int vertical);
void setHorizontalLeds(int red, int green, int yellow);
void setVerticalLeds(int red, int green, int yellow);
void setPedesLeds(int red, int green, int mixed);

extern int red_duration;
extern int green_duration;
extern int yellow_duration;
extern int pedeson;

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim3;

#endif /* INC_GLOBAL_H_ */
