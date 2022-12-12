/*
 * scheduler.c
 *
 *  Created on: Oct 31, 2022
 *      Author: phamv
 */
#include "scheduler.h"

struct sTask SCH_tasks_G[SCH_MAX_TASKS];
struct sTask *head = NULL;
struct sTask *pRun = NULL;
void SCH_Init(void){
	unsigned char i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

void SCH_Update(void){
//	uint32_t index;
//	for(index = 0; index < SCH_MAX_TASKS; index++){
//		if(SCH_tasks_G[index].pTask){
//			if(SCH_tasks_G[index].Delay > 0){
//				SCH_tasks_G[index].Delay--;
//			} else {
//				SCH_tasks_G[index].RunMe += 1;
//				SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
//			}
//		}
//	}
	if(head != NULL){
		head->Delay--;
	}
	while(head != NULL && head->Delay == 0){
		if(head->Period != 0) SCH_Add_Task(head->pTask, head->Period, head->Period);
		head = head->pNext;
	}
}

uint32_t SCH_Add_Task(void(*pFunc)(), uint32_t delay, uint32_t period){
//	uint32_t index = 0;
//	while(SCH_tasks_G[index].pTask != 0 && index < SCH_MAX_TASKS) index++;
//	if(index == SCH_MAX_TASKS){
//		return SCH_MAX_TASKS;
//	}
//	SCH_tasks_G[index].pTask = pFunc;
//	SCH_tasks_G[index].Period = period;
//	SCH_tasks_G[index].Delay = delay;
//	SCH_tasks_G[index].RunMe = 0;
//	SCH_tasks_G[index].TaskID = index;
//	return index;
	uint32_t index = 0;
	uint8_t waiting = 0;
	while(SCH_tasks_G[index].pTask != 0 && index < SCH_MAX_TASKS) index++;
	if(index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[index].pTask = pFunc;
	SCH_tasks_G[index].Period = period;
	SCH_tasks_G[index].RunMe = 0;
	SCH_tasks_G[index].TaskID = index;
	struct sTask *cur = head;
	struct sTask *prev = NULL;
	if(head == NULL){
		head = &SCH_tasks_G[index];
		SCH_tasks_G[index].Delay = delay;
		pRun = head;
	} else {
		while(cur != NULL){
			waiting += cur->Delay;
			if(waiting > delay) break;
			prev = cur;
			cur = cur->pNext;
		}
		if(cur == NULL){
			prev->pNext = &SCH_tasks_G[index];
			SCH_tasks_G[index].Delay = delay - waiting;
		} else{
			if(cur == head){
				head = &SCH_tasks_G[index];
				head->pNext = cur;
				head->Delay = delay;
				if(pRun == cur) pRun = head;
			} else {
				prev->pNext =  &SCH_tasks_G[index];
				SCH_tasks_G[index].Delay = delay - waiting + cur->Delay;
				SCH_tasks_G[index].pNext = cur;
			}
			cur->Delay -= SCH_tasks_G[index].Delay;
//			while(cur != NULL){
//				if(cur->Delay > 0){
//					cur->Delay -= SCH_tasks_G[index].Delay;
//				}
//				cur = cur->pNext;
//			}
		}
	}
	return index;
}

void SCH_Dispatch_Tasks(void){
//	for(int index = 0; index < SCH_MAX_TASKS; index++){
//		if(SCH_tasks_G[index].RunMe > 0){
//			SCH_tasks_G[index].RunMe--;
//			(*SCH_tasks_G[index].pTask)();
//			if(SCH_tasks_G[index].Period == 0) SCH_Delete_Task(index);
//		}
//	}
//	SCH_Go_To_Sleep();
	while(pRun != head){
		(pRun->pTask)();
		uint32_t id = pRun->TaskID;
		pRun = pRun->pNext;
		SCH_Delete_Task(id);
	}
}

uint8_t SCH_Delete_Task(uint32_t index){
	if(SCH_tasks_G[index].pTask == 0){
		return 0;
	} else {
		SCH_tasks_G[index].pTask = 0;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
		SCH_tasks_G[index].pNext = 0;
		SCH_tasks_G[index].TaskID = 0;
		return 1;
	}
}

//void SCH_Go_To_Sleep(void){
//	HAL_SuspendTick();
//	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
////	HAL_ResumeTick();
//}
