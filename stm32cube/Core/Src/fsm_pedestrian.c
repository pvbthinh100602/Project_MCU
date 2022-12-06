/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */

#include "fsm_pedestrian.h"

void fsm_pedestrian_run(){
	switch(pedestrianStatus) {
		case INIT:
			clearPedestrian();
			pedestrianStatus = PED_NONE;
			break;
		case PED_NONE:
			if(isButtonPressed(0)){
				if(status == AUTO_RED_GREEN || status == MAN_RED_GREEN){
					pedestrianStatus = PED_GREEN;
					setPedestrianGreen();
					__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,10);
				}
				if(status == AUTO_GREEN_RED || status == MAN_GREEN_RED || status == AUTO_YELLOW_RED || status == MAN_YELLOW_RED){
					pedestrianStatus = PED_RED;
					setPedestrianRed();
				}
			}
			break;
		case PED_RED:
			if(status == AUTO_RED_GREEN || status == MAN_RED_GREEN){
				pedestrianStatus = PED_GREEN;
				setPedestrianGreen();
				__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1,10);
			}
			break;
		case PED_GREEN:
			if(status == AUTO_GREEN_RED || status == MAN_GREEN_RED || status == AUTO_YELLOW_RED || status == MAN_YELLOW_RED){
				pedestrianStatus = PED_NONE;
				clearPedestrian();
			}
			break;
		default:
			break;
	}
}
