/*
 * fsm_automatic.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */


#include "global.h"

int buzzer_on = 0;
int buzzer_toggle = 0;
int buzzer_value = 40;

void fsm_automatic_run(){
	switch(status) {
		case INIT:
			status = RED_GREEN;
			int pedesduration = (red_duration + green_duration + yellow_duration)*100;
			setTimer(pedesduration,9);
			setInitialValue(red_duration, green_duration);
			setTimer(green_duration*100, 0);
			setTimer(100, 1);
			setTimer(10, 8);
			buzzer_value = 100;
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			break;
		case RED_GREEN:
			setHorizontalLeds(SET,RESET,RESET);	//D4-5 horizontal
			setVerticalLeds(RESET,SET, RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				buzzer_on = 0;
				buzzer_value = 100;
				//HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				setPedesLeds(RESET, RESET, RESET);
			}
			if(pedeson==1){
				setPedesLeds(RESET, SET, RESET);
			}
			if(buzzer_toggle) {
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, buzzer_value);
				buzzer_value += 79/red_duration;
			}
			else {
			    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			}
			if(timer_flag[0] == 1){
				//setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
				status = RED_YELLOW;
				setInitialValue(yellow_duration, yellow_duration);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);

			}
			if(timer_flag[8]) {
			    if(buzzer_on) {
			        buzzer_toggle ^= 1;
			    }
			    setTimer(10, 8);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET, RESET);
				setPedesLeds(RESET,RESET,RESET);
				setTimer(100, 3);
				status = MAN_RED;
				printf("=============MANUAL MODE=============\r\n");
				printf("Current time: %d\r\n", red_duration);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				buzzer_on = 1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
				setTimer(10, 8);
			}
			break;
		case RED_YELLOW:
			setHorizontalLeds(SET,RESET,RESET);
			setVerticalLeds(RESET,RESET, SET);
			if(timer_flag[9]==1){
				pedeson=0;
				buzzer_on = 0;
				buzzer_value = 100;
				setPedesLeds(RESET, RESET, RESET);
				//HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
			}
			if(pedeson==1){
				setPedesLeds(RESET, SET, RESET);
			}
			if(buzzer_toggle) {
                __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, buzzer_value);
                buzzer_value += 79/red_duration;
            }
            else {
                __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
            }
			if(timer_flag[0] == 1){
				//setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = GREEN_RED;
				buzzer_on = 0;
				buzzer_value = 100;
				setInitialValue(green_duration, red_duration);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(timer_flag[8]) {
				if(buzzer_on) {
				    buzzer_toggle ^= 1;
				}
				setTimer(10, 8);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(RESET,SET,RESET);
				pedeson=1;
				buzzer_on = 1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
				setTimer(10, 8);
			}
			break;
		case GREEN_RED:
			setHorizontalLeds(RESET,SET,RESET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				buzzer_on = 0;
				setPedesLeds(RESET, RESET, RESET);
				//HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			}
			if(timer_flag[0] == 1){
				//setPedesLeds(RESET,RESET,RESET);
				setTimer(yellow_duration*100, 0);
				status = YELLOW_RED;
				setInitialValue(yellow_duration, yellow_duration);
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				buzzer_on = 1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
				setTimer(10, 8);
			}
			break;
		case YELLOW_RED:
			setHorizontalLeds(RESET,RESET,SET);
			setVerticalLeds(SET,RESET,RESET);
			if(timer_flag[9]==1){
				pedeson=0;
				buzzer_on = 0;
				setPedesLeds(RESET, RESET, RESET);
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			}
			if(pedeson==1){
				setPedesLeds(SET, RESET, RESET);
				setTimer(10, 8);
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
			}
			if(timer_flag[0] == 1){
				//setPedesLeds(RESET,RESET,RESET);
				setTimer(green_duration*100, 0);
				status = RED_GREEN;
				setInitialValue(red_duration, green_duration);
				if(pedeson) buzzer_on = 1;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(0) == 1){
				setPedesLeds(SET,RESET,RESET);
				pedeson=1;
				buzzer_on = 1;
				int pedesduration = (red_duration+green_duration+yellow_duration)*200;
				setTimer(pedesduration,9);
				setTimer(10, 8);
			}
			break;
		default:
			break;
	}
}
