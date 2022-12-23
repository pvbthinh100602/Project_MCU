/*
 * scheduler.c
 *
 *  Created on: Oct 31, 2022
 *      Author: phamv
 */
#include "scheduler.h"

struct sTask SCH_tasks_G[SCH_MAX_TASKS];
struct sTask *head = NULL;
void SCH_Init(void){
	unsigned char i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

void SCH_Update(void){
	if(head != NULL){
		head->Delay--;
	}
}

uint32_t SCH_Add_Task(void(*pFunc)(), uint32_t delay, uint32_t period){
	uint32_t index = 0;
	uint8_t waiting = 0;
	while(SCH_tasks_G[index].pTask != 0 && index < SCH_MAX_TASKS) index++;
	if(index == SCH_MAX_TASKS){
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[index].pTask = pFunc;
	SCH_tasks_G[index].Period = period;
	SCH_tasks_G[index].TaskID = index;
	struct sTask *cur = head;
	struct sTask *prev = NULL;
	if(head == NULL){
		head = &SCH_tasks_G[index];
		SCH_tasks_G[index].Delay = delay;
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
			} else {
				prev->pNext =  &SCH_tasks_G[index];
				SCH_tasks_G[index].Delay = delay - waiting + cur->Delay;
				SCH_tasks_G[index].pNext = cur;
			}
			cur->Delay -= SCH_tasks_G[index].Delay;
		}
	}
	return index;
}

void SCH_Dispatch_Tasks(void){
	if(head != NULL && head->Delay == 0){
		(*head->pTask)();
		if(head->Period != 0) SCH_Add_Task(head->pTask, head->Period, head->Period);
		uint32_t del_index = head->TaskID;
		head = head->pNext;
		SCH_Delete_Task(del_index);
	}
}

uint8_t SCH_Delete_Task(uint32_t index){
	if(SCH_tasks_G[index].pTask == 0){
		return 0;
	} else {
		SCH_tasks_G[index].pTask = 0;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].pNext = 0;
		SCH_tasks_G[index].TaskID = 0;
		return 1;
	}
}
