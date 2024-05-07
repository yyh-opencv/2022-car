#ifndef __ENCODER_H
#define __ENCODER_H

extern int iTim1Encoder;//��Ŵ�TIM1��ʱ���������ı���������   ����
extern int iTim4Encoder;//��Ŵ�TIM4��ʱ���������ı���������		����
extern int iTim5Encoder;//��Ŵ�TIM5��ʱ���������ı���������		����
extern int iTim8Encoder;//��Ŵ�TIM8��ʱ���������ı���������		����

extern int Tim1Encoder;//  ����
extern int Tim4Encoder;//	����
extern int Tim5Encoder;//	����
extern int Tim8Encoder;//  ����

extern int a,b,c,d;

int GetTim1Encoder(void);//��������
int GetTim4Encoder(void);
int GetTim5Encoder(void);
int GetTim8Encoder(void);
void ALL_Encoder(void);
void SetMotorVoltageAndDirection_SR(int nMotorPwm);//���õ����ѹ�ͷ���
void SetMotorVoltageAndDirection_SL(int nMotorPwm);//���õ����ѹ�ͷ���
void SetMotorVoltageAndDirection_XR(int nMotorPwm);//���õ����ѹ�ͷ���
void SetMotorVoltageAndDirection_XL(int nMotorPwm);//���õ����ѹ�ͷ���	
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
