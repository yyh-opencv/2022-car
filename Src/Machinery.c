#include "encoder.h"
#include "Machinery.h"
#include "tim.h"

unsigned int g_n_zuo_LeftMotorPulse;//全局变量，保存左电机脉冲数值
unsigned int g_n_zuo_RightMotorPulse;//全局变量，保存右电机脉冲数值
unsigned int g_n_you_LeftMotorPulse;//全局变量，保存左电机脉冲数值
unsigned int g_n_you_RightMotorPulse;//全局变量，保存右电机脉冲数值

int g_nSpeedTarget_SL = 25;//全局变量，上左电机速度目标值
int g_nSpeedTarget_SR = 25;//全局变量，上右电机速度目标值
int g_nSpeedTarget_XL = 25;//全局变量，下左电机速度目标值
int g_nSpeedTarget_XR =25;//全局变量，下右电机速度目标值

int g_n_S_LeftMotorOutput=0;//左上电机输出
int g_n_S_RightMotorOutput=0;//右上电机
int g_n_X_LeftMotorOutput=0;//左下电机输出
int g_n_X_RightMotorOutput=0;//右下电机

int aa[6];
int16_t chassis_value[4]; //用来储存Now_out速度返回值。



int nErrorPrev_SL;//上一次偏差值
int nErrorPrev_SR;//上一次偏差值
int nErrorPrev_XL;//上一次偏差值
int nErrorPrev_XR;//上一次偏差值

int nPwmBais_XL,nPwm_XL;//PWM增量，PWM总量
int nPwmBais_XR,nPwm_XR;//PWM增量，PWM总量
int nPwmBais_SL,nPwm_SL;//PWM增量，PWM总量
int nPwmBais_SR,nPwm_SR;//PWM增量，PWM总量

float fP_XL=3, fI_XL=1 ;//这里只用到PI，参数由电机的种类和负载决定
float fP_XR=3 ,fI_XR=1 ;//这里只用到PI，参数由电机的种类和负载决定
float fP_SL =3, fI_SL = 1;//这里只用到PI，参数由电机的种类和负载决定
float fP_SR=3 ,fI_SR= 1; //这里只用到PI，参数由电机的种类和负载决定

//int demo[4];


int SpeedInnerControl_SL(int nPulse,int nTarget)//速度内环控制
{
	int nError_SL;//偏差
	
	
	
	nError_SL = nTarget - nPulse;//偏差 = 目标速度 - 实际速度
	nPwmBais_SL = fP_SL * (nError_SL - nErrorPrev_SL) + fI_SL * nError_SL;//增量式PI控制器
	nErrorPrev_SL = nError_SL;//保存上一次偏差
	nPwm_SL += nPwmBais_SL;//增量输出
	
	
	
	if(nPwm_SL > 50) nPwm_SL = 50;//限制上限，防止超出PWM量程
	if(nPwm_SL <-50) nPwm_SL =-50;
	
//	OutData[0]=(float)nPulse;//速度实际值
//	OutData[1]=(float)nTarget ;//PID速度处理值
	return nPwm_SL;//返回输出值
}
int SpeedInnerControl_SR(int nPulse,int nTarget)//速度内环控制
{
	int nError_SR;//偏差
	
	
	
	nError_SR = nTarget - nPulse;//偏差 = 目标速度 - 实际速度
	nPwmBais_SR = fP_SR * (nError_SR - nErrorPrev_SR) + fI_SR * nError_SR;//增量式PI控制器
	aa[1]=nError_SR;
	aa[2]=fP_SR * (nError_SR - nErrorPrev_SR);
	
	nErrorPrev_SR = nError_SR;//保存上一次偏差
	nPwm_SR += nPwmBais_SR;//增量输出
	if(nPwm_SR > 50) nPwm_SR = 50;//限制上限，防止超出PWM量程
	if(nPwm_SR <-50) nPwm_SR =-50;
	
//	OutData[0]=(float)nPulse;//速度实际值
//	OutData[1]=(float)nTarget ;//PID速度处理值
	return nPwm_SR;//返回输出值
}

int SpeedInnerControl_XL(int nPulse,int nTarget)//速度内环控制
{
	int nError_XL;//偏差
	
	
	
	nError_XL = nTarget - nPulse;//偏差 = 目标速度 - 实际速度
	nPwmBais_XL = fP_XL * (nError_XL - nErrorPrev_XL) + fI_XL * nError_XL;//增量式PI控制器
	aa[3] = nError_XL;
	aa[4] = fP_XL * (nError_XL - nErrorPrev_XL);
	aa[5] = fI_XL * nError_XL;
	nErrorPrev_XL = nError_XL;//保存上一次偏差
	nPwm_XL += nPwmBais_XL;//增量输出
	
	
	
	if(nPwm_XL > 50) nPwm_XL = 50;//限制上限，防止超出PWM量程
	if(nPwm_XL <-50) nPwm_XL =-50;
	
//	OutData[0]=(float)nPulse;//速度实际值
//	OutData[1]=(float)nTarget ;//PID速度处理值
	return nPwm_XL;//返回输出值
}

int SpeedInnerControl_XR(int nPulse,int nTarget)//速度内环控制
{
	int nError_XR;//偏差
	
	
	
	nError_XR = nTarget - nPulse;//偏差 = 目标速度 - 实际速度
//	demo[0] = nError_XR;
	nPwmBais_XR = fP_XR * (nError_XR - nErrorPrev_XR) + fI_XR * nError_XR;//增量式PI控制器
//	demo[1] = fP_XR * (nError_XR - nErrorPrev_XR);
	nErrorPrev_XR = nError_XR;//保存上一次偏差
	nPwm_XR += nPwmBais_XR;//增量输出
//	demo[2] = nPwm_XR;
	
	
	
	if(nPwm_XR > 50) nPwm_XR = 50;//限制上限，防止超出PWM量程
	if(nPwm_XR <-50) nPwm_XR =-50;
	
//	OutData[0]=(float)nPulse;//速度实际值
//	OutData[1]=(float)nTarget ;//PID速度处理值
	return nPwm_XR;//返回输出值
}




/****************************************
函数名：Machinery_all()
作用：通过pid驱动电机;
****************************************/

void Machinery_all(void)
{
	g_n_S_LeftMotorOutput=SpeedInnerControl_SL(Tim5Encoder,g_nSpeedTarget_SL);
	g_n_S_RightMotorOutput=SpeedInnerControl_SR(Tim8Encoder,g_nSpeedTarget_SR);
	g_n_X_LeftMotorOutput=SpeedInnerControl_XL(Tim1Encoder,g_nSpeedTarget_XL);
	g_n_X_RightMotorOutput=SpeedInnerControl_XR(Tim4Encoder,g_nSpeedTarget_XR);
}
void nbplus()
{
	SetMotorVoltageAndDirection_SR(g_n_S_RightMotorOutput);//设置电机电压和方向
	SetMotorVoltageAndDirection_SL(g_n_S_LeftMotorOutput);//设置电机电压和方向
	SetMotorVoltageAndDirection_XR(g_n_X_RightMotorOutput);//设置电机电压和方向
	SetMotorVoltageAndDirection_XL(g_n_X_LeftMotorOutput);//设置电机电压和方向	

}
	


