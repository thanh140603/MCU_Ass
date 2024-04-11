/*
 * fsm_manual.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Admin
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "global.h"
extern int red_duration_clone;
extern int yellow_duration_clone;
extern int green_duration_clone;
extern int toggle;
void fsm_manual_run();
void initializeDurationClones();

#endif /* INC_FSM_MANUAL_H_ */
