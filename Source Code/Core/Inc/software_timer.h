/*
 * software_timer.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int duration, int timerId);
void timerRun(int timerId);

#endif /* INC_SOFTWARE_TIMER_H_ */
