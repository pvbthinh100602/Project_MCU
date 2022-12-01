/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "main.h"
#include "button.h"
#include "traffic.h"
#include "scheduler.h"

#define	INIT			1
#define	AUTO_RED_GREEN	2
#define	AUTO_RED_YELLOW	3
#define	AUTO_GREEN_RED	4
#define	AUTO_YELLOW_RED	5

#define	MAN_RED_GREEN	11
#define	MAN_RED_YELLOW	12
#define	MAN_GREEN_RED	13
#define	MAN_YELLOW_RED	14

#define	TUNING_RED1		21
#define	TUNING_RED2		22
#define	TUNING_GREEN1	23
#define	TUNING_GREEN2	24
#define	TUNING_YELLOW1	25
#define	TUNING_YELLOW2	26

extern int status;
extern int counter;

#endif /* INC_GLOBAL_H_ */
