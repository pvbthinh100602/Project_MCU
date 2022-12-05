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
		status=AUTO_RED_GREEN;
		setTimer1(1000);
		counter = max_red1;
		displayCounter();
		setTraffic1Red();
		setTraffic2Green();
		break;
	case AUTO_RED_GREEN:
		isButtonPressed(0);
		isButtonPressed(2);
		isButtonPressed(3);
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == max_yellow2){
				setTraffic2Yellow();
				status=AUTO_RED_YELLOW;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			status=MAN_RED_GREEN;
			setTimer1(60000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 99;
			displayCounter();
			break;
		}
		break;
	case AUTO_RED_YELLOW:
		isButtonPressed(0);
		isButtonPressed(2);
		isButtonPressed(3);
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_green1;
				setTraffic1Green();
				setTraffic2Red();
				status=AUTO_GREEN_RED;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			status=MAN_RED_GREEN;
			setTimer1(60000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 99;
			displayCounter();
			break;
		}
		break;

	case AUTO_GREEN_RED:
		isButtonPressed(0);
		isButtonPressed(2);
		isButtonPressed(3);
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_yellow1;
				setTraffic1Yellow();
				status=AUTO_YELLOW_RED;
			}
			displayCounter();
		}

		if(isButtonPressed(1)){
			status=MAN_RED_GREEN;
			setTimer1(60000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 99;
			displayCounter();
			break;
		}
		break;

	case AUTO_YELLOW_RED:
		isButtonPressed(0);
		isButtonPressed(2);
		isButtonPressed(3);
		if(timer1_flag == 1){
			counter--;
			setTimer1(1000);
			if(counter == 0){
				counter = max_red1;
				setTraffic1Red();
				setTraffic2Green();
				status=AUTO_RED_GREEN;
			}
			displayCounter();
		}

		if(isButtonPressed(1)==1){
			status=MAN_RED_GREEN;
			setTimer1(60000);
			setTraffic1Red();
			setTraffic2Green();
			counter = 99;
			displayCounter();
			break;
		}
		break;
	}

}
