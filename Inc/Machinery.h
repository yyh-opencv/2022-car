#ifndef __MACHINERY_H
#define __MACHINERY_H

#include "main.h"
#include "stm32f1xx_hal.h"


//typedef struct
//{
//	int Now;//本次误差
//	int Last;//上次误差
//	int earlier;//上上次误差
//	int Last_out; //上次的输出
//	int Now_out; //本次输出
//	
//}Error;  //pid运算误差结构体，可存放不同电机的pid运算数据，达到一个pid函数给多个电机使用的效果

//int PID_chassis(Error *chas_error,int speed_now,int speed_exp,float kp,float ki,float kd);
extern int g_nSpeedTarget_SL ;//全局变量，上左电机速度目标值
extern int g_nSpeedTarget_SR ;//全局变量，上右电机速度目标值
extern int g_nSpeedTarget_XL ;//全局变量，下左电机速度目标值
extern int g_nSpeedTarget_XR ;//全局变量，下右电机速度目标值
int SpeedInnerControl_XR(int nPulse,int nTarget);
int SpeedInnerControl_XL(int nPulse,int nTarget);
int SpeedInnerControl_SR(int nPulse,int nTarget);
int SpeedInnerControl_SL(int nPulse,int nTarget);

void Machinery_all(void);
void nbplus(void);
#endif
