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
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_RED2;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}

		break;
	case TUNING_RED2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Red();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}
		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_GREEN1;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_GREEN1:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic1Green();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_GREEN2;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_GREEN2:

		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Green();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_YELLOW1;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_YELLOW1:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic1Yellow();
		}
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_YELLOW2;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_YELLOW2:
		if(timer1_flag){
			timer1_flag = 0;
			setTimer1(1000);
			toggleTraffic2Yellow();
		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_green2*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			status = TUNING_RED1;
			setTimer1(1000);
			clearTraffic1();
			clearTraffic2();
		}

		if(isButtonPressed(3)){

		}
		break;
	default:
		break;
	}
}
