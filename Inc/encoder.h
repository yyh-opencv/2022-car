#ifndef __ENCODER_H
#define __ENCODER_H

extern int iTim1Encoder;//存放从TIM1定时器读出来的编码器脉冲   下左
extern int iTim4Encoder;//存放从TIM4定时器读出来的编码器脉冲		下右
extern int iTim5Encoder;//存放从TIM5定时器读出来的编码器脉冲		上左
extern int iTim8Encoder;//存放从TIM8定时器读出来的编码器脉冲		上右

extern int Tim1Encoder;//  下左
extern int Tim4Encoder;//	下右
extern int Tim5Encoder;//	上左
extern int Tim8Encoder;//  上右

extern int a,b,c,d;

int GetTim1Encoder(void);//声明函数
int GetTim4Encoder(void);
int GetTim5Encoder(void);
int GetTim8Encoder(void);
void ALL_Encoder(void);
void SetMotorVoltageAndDirection_SR(int nMotorPwm);//设置电机电压和方向
void SetMotorVoltageAndDirection_SL(int nMotorPwm);//设置电机电压和方向
void SetMotorVoltageAndDirection_XR(int nMotorPwm);//设置电机电压和方向
void SetMotorVoltageAndDirection_XL(int nMotorPwm);//设置电机电压和方向	
void ALL_Direction(void);
typedef struct
{
	int angle;     //
	int speed;     //
	int current;   //
	int celsius;   //
}MotoData;

extern MotoData Moto_1;//
extern MotoData Moto_2;//
extern MotoData Moto_3;
extern MotoData Moto_4;
#endif
