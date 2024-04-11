/*
 * button.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#include "button.h"

int button_flag[4] = {0};
int KeyReg[4][4] = {
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
};
int TimerForKeyPress = 200;

int button_ports[4] = {A0_GPIO_Port, A1_GPIO_Port, A2_GPIO_Port, A3_GPIO_Port};
int button_pins[4] = {A0_Pin, A1_Pin, A2_Pin, A3_Pin};

int isButtonPressed(int key){
	if(button_flag[key] == 1){
		button_flag[key] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int key){
	button_flag[key] = 1;
}
void getKeyInput(int key){
	KeyReg[key][0] = KeyReg[key][1];
	KeyReg[key][1] = KeyReg[key][2];
	KeyReg[key][2] = HAL_GPIO_ReadPin(button_ports[key],button_pins[key]);
	if((KeyReg[key][0] == KeyReg[key][1]) && (KeyReg[key][1] == KeyReg[key][2])){
		if(KeyReg[key][3] != KeyReg[key][2]){
			KeyReg[key][3] = KeyReg[key][2];
			if(KeyReg[key][2] == PRESSED_STATE){
				subKeyProcess(key);
				TimerForKeyPress = 200;
			}
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				KeyReg[key][3] = NORMAL_STATE;
			}
		}
	}
}
