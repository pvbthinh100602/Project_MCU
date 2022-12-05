/*
 * fsm_manual.c
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */
#include "fsm_manual.h"

void fsm_manual_run(){

	switch (status) {

		case MAN_RED_GREEN:
			clearTraffic1();
			clearTraffic2();
			setTraffic1Red();
			setTraffic2Green();
			if (isButtonPressed(2)) {
				status = MAN_RED_YELLOW;
				setTimer1(60000);
			}
			else if (!isButtonPressed(2)) if (timer1_flag) status = AUTO_RED_YELLOW;
			if (isButtonPressed(1)) status = TUNING_RED1;
			break;

		case MAN_RED_YELLOW:
			clearTraffic1();
			clearTraffic2();
			setTraffic1Red();
			setTraffic2Yellow();
			if (isButtonPressed(2)) {
				status = MAN_GREEN_RED;
				setTimer1(60000);
			}
			else if (!isButtonPressed(2)) if (timer1_flag) status = AUTO_GREEN_RED;
			if (isButtonPressed(1)) status = TUNING_RED1;
			break;

		case MAN_GREEN_RED:
			clearTraffic1();
			clearTraffic2();
			setTraffic1Green();
			setTraffic2Red();
			if (isButtonPressed(2)) {
				status = MAN_YELLOW_RED;
				setTimer1(60000);
			}
			else if (!isButtonPressed(2)) if (timer1_flag) status = AUTO_YELLOW_RED;
			if (isButtonPressed(1)) status = TUNING_RED1;
			break;

		case MAN_YELLOW_RED:
			clearTraffic1();
			clearTraffic2();
			setTraffic1Yellow();
			setTraffic2Red();
			if (isButtonPressed(2)) {
				status = MAN_RED_GREEN;
				setTimer1(60000);
			}
			else if (!isButtonPressed(2)) if (timer1_flag) status = AUTO_RED_GREEN;
			if (isButtonPressed(1)) status = TUNING_RED1;
			break;

		default:
			break;
	}
}

