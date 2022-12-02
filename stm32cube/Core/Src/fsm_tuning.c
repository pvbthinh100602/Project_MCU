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

		}

		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
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
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){

		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_GREEN1:
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){

		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_GREEN2:
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){

		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_YELLOW1:
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){

		}

		if(isButtonPressed(3)){

		}
		break;
	case TUNING_YELLOW2:
		if(isButtonPressed(1)){
			status = AUTO_RED_GREEN;
			setTimer1(max_red*1000);
			setTraffic1Red();
			setTraffic2Green();
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){

		}

		if(isButtonPressed(3)){

		}
		break;
	default:
		break;
	}
}
