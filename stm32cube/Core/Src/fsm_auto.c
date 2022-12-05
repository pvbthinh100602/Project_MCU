/*
 * fsm_auto.c
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */

#include "fsm_auto.h"

void fsm_auto_run(){

	switch (status)
	{
	case INIT:
		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			break;
		}
		setTimer1(1000);

		counter=max_red1;
		counter2=max_green2;

		setTraffic1Red();
		setTraffic2Green();

		status=AUTO_RED_GREEN;

		break;

	case AUTO_RED_GREEN:
		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			break;
		}
		if(timer1_flag==1){
			counter--;
			counter2--;
			setTimer1(1000);
			if(counter2==0){
				counter2=max_yellow2;
				setTraffic2Yellow();
				status=AUTO_RED_YELLOW;
			}
		}
		break;

	case AUTO_RED_YELLOW:
		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			break;
		}
		if(timer1_flag==1){
			counter--;
			counter2--;
			setTimer1(1000);
			if(counter2==0){
				counter=max_green1;
				counter2=max_red2;
				setTraffic1Green();
				setTraffic2Red();
				status=AUTO_GREEN_RED;
			}
		}
		break;

	case AUTO_GREEN_RED:
		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			break;
		}
		if(timer1_flag==1){
			counter--;
			counter2--;
			setTimer1(1000);
			if(counter==0){
				counter=max_yellow1;
				setTraffic1Yellow();
				status=AUTO_YELLOW_RED;
			}
		}
		break;

	case AUTO_YELLOW_RED:
		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			break;
		}
		if(timer1_flag==1){
			counter--;
			counter2--;
			setTimer1(1000);
			if(counter==0){
				counter=max_red1;
				counter2=max_green2;
				setTraffic1Red();
				setTraffic2Green();
				status=AUTO_RED_GREEN;
			}
		}
		break;
	}

}
