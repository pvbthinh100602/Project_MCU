/*
 * fsm_tuning.c
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */
#include "fsm_tuning.h"

void fsm_tuning_run(){
	switch(status){
	case TUNING_RED1:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic1Red();
		}

		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			status = AUTO_RED_GREEN;
			acceptTraffic1Red();
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_RED2;
			setTimer1(1000);
			acceptTraffic1Red();
			counter = max_red2;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > 99){
				counter = 2;
			}
		}

		break;
	case TUNING_RED2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Red();
		}

		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			acceptTraffic2Red();
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}
		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_GREEN1;
			setTimer1(1000);
			acceptTraffic2Red();
			counter = max_green1;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > 99){
				counter = 2;
			}
		}
		break;
	case TUNING_GREEN1:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic1Green();
		}

		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			acceptTraffic1Green();
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_GREEN2;
			setTimer1(1000);
			acceptTraffic1Green();
			counter = max_green2;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > max_red2 - 1){
				counter = 1;
			}
		}
		break;
	case TUNING_GREEN2:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Green();
		}

		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			status = AUTO_RED_GREEN;
			acceptTraffic2Green();
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_YELLOW1;
			setTimer1(1000);
			acceptTraffic2Green();
			counter = max_yellow1;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > max_red1 - 1){
				counter = 1;
			}
		}
		break;
	case TUNING_YELLOW1:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic1Yellow();
		}
		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			status = AUTO_RED_GREEN;
			acceptTraffic1Yellow();
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_YELLOW2;
			setTimer1(1000);
			acceptTraffic1Yellow();
			counter = max_yellow2;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > max_red2 - 1){
				counter = 1;
			}
		}
		break;
	case TUNING_YELLOW2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Yellow();
		}

		if(isButtonPressed(1)){
			isButtonPressed(2);
			isButtonPressed(3);
			status = AUTO_RED_GREEN;
			acceptTraffic2Yellow();
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = TUNING_RED1;
			setTimer1(1000);
			acceptTraffic2Yellow();
			counter = max_red1;
			clearTraffic1();
			clearTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			counter++;
			if(counter > max_red1 - 1){
				counter = 1;
			}
		}
		break;
	default:
		break;
	}
}
