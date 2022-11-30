/*
 * traffic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: phamv
 */
#include "traffic.h"

void setTraffic1Red(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);

}

void setTraffic2Red(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
}

void setTraffic1Green(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
}

void clearTraffic1(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_RESET);
}

void setTraffic2Green(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
}

void setTraffic1Yellow(){
	HAL_GPIO_WritePin(TrafficLight1_0_GPIO_Port, TrafficLight1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight1_1_GPIO_Port, TrafficLight1_1_Pin, GPIO_PIN_SET);
}

void setTraffic2Yellow(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_SET);
}

void clearTraffic2(){
	HAL_GPIO_WritePin(TrafficLight2_0_GPIO_Port, TrafficLight2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TrafficLight2_1_GPIO_Port, TrafficLight2_1_Pin, GPIO_PIN_RESET);
}

void setPedestrianRed(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}

void setPedestrianGreen(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void setPedestrianYellow(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void clearPedestrian(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}

