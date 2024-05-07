#ifndef __MACHINERY_H
#define __MACHINERY_H

#include "main.h"
#include "stm32f1xx_hal.h"


//typedef struct
//{
//	int Now;//�������
//	int Last;//�ϴ����
//	int earlier;//���ϴ����
//	int Last_out; //�ϴε����
//	int Now_out; //�������
//	
//}Error;  //pid�������ṹ�壬�ɴ�Ų�ͬ�����pid�������ݣ��ﵽһ��pid������������ʹ�õ�Ч��

//int PID_chassis(Error *chas_error,int speed_now,int speed_exp,float kp,float ki,float kd);
extern int g_nSpeedTarget_SL ;//ȫ�ֱ������������ٶ�Ŀ��ֵ
extern int g_nSpeedTarget_SR ;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
extern int g_nSpeedTarget_XL ;//ȫ�ֱ������������ٶ�Ŀ��ֵ
extern int g_nSpeedTarget_XR ;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
int SpeedInnerControl_XR(int nPulse,int nTarget);
int SpeedInnerControl_XL(int nPulse,int nTarget);
int SpeedInnerControl_SR(int nPulse,int nTarget);
int SpeedInnerControl_SL(int nPulse,int nTarget);

void Machinery_all(void);
void nbplus(void);
#endif
