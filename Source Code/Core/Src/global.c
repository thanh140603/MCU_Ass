/*
 * global.c
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#include"global.h"

int status=0;
int horizontal_number=0;
int vertical_number=0;
int red_duration=5;
int green_duration=3;
int yellow_duration=2;
int index_led=0;
int pedeson=0;	//used to check whether ped button is pressed or not

int __io_putchar(int ch) {
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

//time counting down
void countDown(){
	horizontal_number--;
	vertical_number--;
        printf("Remaining horizontal second: %d\r\n", horizontal_number);
        printf("Remaining vertical second: %d\r\n", vertical_number);
}

void setInitialValue(int horizontal, int vertical){
    horizontal_number = horizontal;
    vertical_number = vertical;
    printf("Remaining horizontal second: %d\r\n", horizontal_number);
    printf("Remaining vertical second: %d\r\n", vertical_number);
}

void setHorizontalLeds(int red, int green, int yellow){
    if(red == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
    }
    if(green == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
    }
    if(yellow == SET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
    }
    if(red==RESET && green==RESET && yellow==RESET){
        HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
        HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
    }
}
void setVerticalLeds(int red, int green, int yellow){
    if(red == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
    }
    if(green == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
    }
    if(yellow == SET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
    }
    if(red==RESET && green==RESET && yellow==RESET){
        HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
        HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
    }
}

void setPedesLeds(int red, int green, int mixed){
    if(red == SET){
        HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
        HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
    }
    if(green == SET){
        HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
        HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
    }
    if(mixed == SET){
        HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
        HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
    }
    if(red==RESET && green==RESET && mixed==RESET){
        HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
        HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
    }
//    HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
//    HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);	Toggle Led error
}
