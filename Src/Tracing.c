#include "Tracing.h"
#include "Machinery.h"
#include "tim.h"
/***************************
函数名：Tracing();
作用：用于寻轨；黑线回1，白线是0;
***************************/
extern uint8_t Rx_dat;
extern int a;
void Tracing()
{	
	//中间三灯灭，正常，走直线
 if(((Left_3)==1)&&((Midlight)==1)&&((Right_3)==1))
	{
		g_nSpeedTarget_SL = 25;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR = 25;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = 25;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =25;//全局变量，下右电机速度目标值
	}
	
	//小偏左，有轮小减速
	else if(((Left_3)==0)&&((Midlight)==1)&&((Right_3)==1))
	{
		g_nSpeedTarget_SL = 25;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR =24;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = 25;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =24;//全局变量，下右电机速度目标值
	}
	//小偏，左轮小减速
	else if(((Left_3)==1)&&((Midlight)==1)&&((Right_3)==0))
	{
		g_nSpeedTarget_SL = 24;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR = 25;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = 24;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =25;//全局变量，下右电机速度目标值
	}
	else if(((Left_3)==0)&&((Midlight)==0)&&((Right_3)==0)&&((Right_1)==0)&&((Left_1)==0))
	{
		g_nSpeedTarget_SL = 20;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR =20;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = 20;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =20;//全局变量，下右电机速度目标值
	}
	

	else if(((((Left_1)==1)||((Left_2)==1))&&(Right_1)==0))
	{
		g_nSpeedTarget_SL = -20;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR = 40;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = -20;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =40;//全局变量，下右电机速度目标值
	}
	else if(((((Right_1)==1)||((Right_2)==1))&&(Left_1)==0))
	{
		g_nSpeedTarget_SL = 40;//全局变量，上左电机速度目标值
		g_nSpeedTarget_SR = -20;//全局变量，上右电机速度目标值
		g_nSpeedTarget_XL = 40;//全局变量，下左电机速度目标值
		g_nSpeedTarget_XR =-20;//全局变量，下右电机速度目标值
	}
}





