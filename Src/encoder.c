#include "tim.h"//包含tim头文件
#include "encoder.h"
int iTim1Encoder;//存放从TIM1定时器读出来的编码器脉冲   下左
int iTim4Encoder;//存放从TIM4定时器读出来的编码器脉冲		下右
int iTim5Encoder;//存放从TIM5定时器读出来的编码器脉冲		上左
int iTim8Encoder;//存放从TIM8定时器读出来的编码器脉冲		上右


int Tim1Encoder;//  下左
int Tim4Encoder;//	下右
int Tim5Encoder;//	上左
int Tim8Encoder;//  上右

MotoData Moto_1;
MotoData Moto_2;
MotoData Moto_3;
MotoData Moto_4;




/*************************************************************

函数名：GetTim1Encoder();
				GetTim4Encoder();
				GetTim5Encoder();
				GetTim8Encoder();

作用：读取利用编码器读取电机 
14ms的脉冲
**************************************************************/

int GetTim1Encoder(void)//获取TIM1定时器读出来的编码器脉冲
{
	iTim1Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim1));//先读取脉冲数
  	__HAL_TIM_SET_COUNTER(&htim1,0);//再计数器清零
	return -iTim1Encoder;//返回脉冲数
}
int GetTim4Encoder(void)//获取TIM4定时器读出来的编码器脉冲
{
	iTim4Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim4));//先读取脉冲数
	__HAL_TIM_SET_COUNTER(&htim4,0);//再计数器清零
	return iTim4Encoder;//返回脉冲数
}

int GetTim5Encoder(void)//获取TIM5定时器读出来的编码器脉冲
{
	iTim5Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim5));//先读取脉冲数
	__HAL_TIM_SET_COUNTER(&htim5,0);//再计数器清零
	return iTim5Encoder;//返回脉冲数
}

int GetTim8Encoder(void)//获取TIM8定时器读出来的编码器脉冲
{
	iTim8Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim8));//先读取脉冲数
	__HAL_TIM_SET_COUNTER(&htim8,0);//再计数器清零
	return -iTim8Encoder;//返回脉冲数
}



/************************************
函数名:SetMotorVoltageAndDirection()
重要转换的常量：int Tem3Encoder_R;  
								int Tem2Encoder_L;
作用：将反转的数据转换为正数。再通过PID
传进占空比调节。因为占空比只能是正数
************************************/
void SetMotorVoltageAndDirection_SR(int nMotorPwm)//设置电机电压和方向
{
	
	if(nMotorPwm < 0)//反转
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);//初始化BIN2引脚为高电
		nMotorPwm = (-nMotorPwm);//如果计算值是负值，先取负得正，因为PWM寄存器只能是正值
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);//初始化BIN2引脚为高电?
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, nMotorPwm);
	}

}
void SetMotorVoltageAndDirection_SL(int nMotorPwm)//设置电机电压和方向
{
	
	if(nMotorPwm < 0)//反转
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);//初始化BIN2引脚为高电平
		nMotorPwm = (-nMotorPwm);//如果计算值是负值，先取负得正，因为PWM寄存器只能是正值
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);//初始化BIN2引脚为高电平
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, nMotorPwm);
	}

}

void SetMotorVoltageAndDirection_XL(int nMotorPwm)//设置电机电压和方向
{
	
	if(nMotorPwm < 0)//反转
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);//初始化BIN2引脚为高电平
		nMotorPwm = (-nMotorPwm);//如果计算值是负值，先取负得正，因为PWM寄存器只能是正值
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);//初始化BIN2引脚为高电平
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, nMotorPwm);
	}

}
void SetMotorVoltageAndDirection_XR(int nMotorPwm)//设置电机电压和方向
{
	
	if(nMotorPwm < 0)//反转
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//初始化BIN1引脚为低电平
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);//初始化BIN2引脚为高电平
		nMotorPwm = (-nMotorPwm);//如果计算值是负值，先取负得正，因为PWM寄存器只能是正值
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, nMotorPwm);
	}
	else
	{
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//初始化BIN1引脚为高电平
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);//初始化BIN2引脚为低电?
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, nMotorPwm);
	}

}



/*************************************************************************************************************************************/
/*************************************************************

函数名：ALL_Encoder();
作用：对编码器函数的整合

**************************************************************/
void ALL_Encoder()
{
		Tim1Encoder=GetTim1Encoder();
		Tim4Encoder=GetTim4Encoder();
		Tim5Encoder=GetTim5Encoder();
		Tim8Encoder=GetTim8Encoder();
}


