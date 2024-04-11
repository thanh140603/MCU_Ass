/*
 * fsm_manual.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#include "fsm_manual.h"

int red_duration_clone;
int yellow_duration_clone;
int green_duration_clone;
int toggle = 1;
void initializeDurationClones(){
    red_duration_clone = red_duration;
    yellow_duration_clone = yellow_duration;
    green_duration_clone = green_duration;
}
void fsm_manual_run(){

	switch (status) {
		case MAN_RED:
			if(timer_flag[3] == 1){
				if(toggle){
					setHorizontalLeds(SET,RESET,RESET);
					setVerticalLeds(SET,RESET,RESET);
				}else {
					setHorizontalLeds(RESET,RESET,RESET);
					setVerticalLeds(RESET,RESET,RESET);
				}
				toggle = 1 - toggle;
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET,RESET);
				setTimer(100, 3);
				status = MAN_YELLOW;
				printf("Current time: %d\r\n", yellow_duration_clone);
			}
			if(isButtonPressed(2) == 1){
				red_duration_clone++;
				if(red_duration_clone >= 99) red_duration_clone = red_duration;
				printf("Current time: %d\r\n", red_duration_clone);
			}
			if(isButtonPressed(3) == 1){
				red_duration =  red_duration_clone;
				green_duration = red_duration - yellow_duration;
				status = INIT;
			}
			break;
		case MAN_YELLOW:
			if(timer_flag[3] == 1){
				if(toggle){
					setHorizontalLeds(RESET,RESET,SET);
					setVerticalLeds(RESET,RESET,SET);
				}else {
					setHorizontalLeds(RESET,RESET,RESET);
					setVerticalLeds(RESET,RESET,RESET);
				}
				toggle = 1 - toggle;
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET,RESET);
				setTimer(100, 3);
				status = MAN_GREEN;
				printf("Current time: %d\r\n", green_duration_clone);
			}
			if(isButtonPressed(2) == 1){
				yellow_duration_clone++;
				if(yellow_duration_clone >= 99) yellow_duration_clone = yellow_duration;
				printf("Current time: %d\r\n", yellow_duration_clone);
			}
			if(isButtonPressed(3) == 1){
				yellow_duration =  yellow_duration_clone;
				red_duration = green_duration + yellow_duration;
				status = INIT;
			}
			break;
		case MAN_GREEN:
			if(timer_flag[3] == 1){
				if(toggle){
					setHorizontalLeds(RESET,SET,RESET);
					setVerticalLeds(RESET,SET,RESET);
				}else {
					setHorizontalLeds(RESET,RESET,RESET);
					setVerticalLeds(RESET,RESET,RESET);
				}
				toggle = 1 - toggle;
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(RESET,RESET,RESET);
				setVerticalLeds(RESET,RESET,RESET);
				status = INIT;
			}
			if(isButtonPressed(2) == 1){
				green_duration_clone++;
				if(green_duration_clone >= 99) green_duration_clone = green_duration;
				printf("Current time: %d\r\n", green_duration_clone);
			}
			if(isButtonPressed(3) == 1){
				green_duration =  green_duration_clone;
				red_duration = green_duration + yellow_duration;
				status = INIT;
			}
			break;
		default:
			initializeDurationClones();
			break;
	}
}
