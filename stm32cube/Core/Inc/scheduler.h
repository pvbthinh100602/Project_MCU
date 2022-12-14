/*
 * scheduler.h
 *
 *  Created on: Oct 31, 2022
 *      Author: phamv
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#include "timer.h"

struct sTask{
	void (* pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint32_t TaskID;
	struct sTask* pNext;
};

#define SCH_MAX_TASKS 20
#define NO_TASK_ID 0

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void(*pFunc)(), uint32_t delay, uint32_t period);
uint8_t SCH_Delete_Task(uint32_t taskID);
void SCH_Go_To_Sleep(void);
#endif /* INC_SCHEDULER_H_ */
