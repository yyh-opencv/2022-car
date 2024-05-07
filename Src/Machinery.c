#include "encoder.h"
#include "Machinery.h"
#include "tim.h"

unsigned int g_n_zuo_LeftMotorPulse;//ȫ�ֱ�������������������ֵ
unsigned int g_n_zuo_RightMotorPulse;//ȫ�ֱ����������ҵ��������ֵ
unsigned int g_n_you_LeftMotorPulse;//ȫ�ֱ�������������������ֵ
unsigned int g_n_you_RightMotorPulse;//ȫ�ֱ����������ҵ��������ֵ

int g_nSpeedTarget_SL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
int g_nSpeedTarget_SR = 25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
int g_nSpeedTarget_XL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
int g_nSpeedTarget_XR =25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ

int g_n_S_LeftMotorOutput=0;//���ϵ�����
int g_n_S_RightMotorOutput=0;//���ϵ��
int g_n_X_LeftMotorOutput=0;//���µ�����
int g_n_X_RightMotorOutput=0;//���µ��

int aa[6];
int16_t chassis_value[4]; //��������Now_out�ٶȷ���ֵ��



int nErrorPrev_SL;//��һ��ƫ��ֵ
int nErrorPrev_SR;//��һ��ƫ��ֵ
int nErrorPrev_XL;//��һ��ƫ��ֵ
int nErrorPrev_XR;//��һ��ƫ��ֵ

int nPwmBais_XL,nPwm_XL;//PWM������PWM����
int nPwmBais_XR,nPwm_XR;//PWM������PWM����
int nPwmBais_SL,nPwm_SL;//PWM������PWM����
int nPwmBais_SR,nPwm_SR;//PWM������PWM����

float fP_XL=3, fI_XL=1 ;//����ֻ�õ�PI�������ɵ��������͸��ؾ���
float fP_XR=3 ,fI_XR=1 ;//����ֻ�õ�PI�������ɵ��������͸��ؾ���
float fP_SL =3, fI_SL = 1;//����ֻ�õ�PI�������ɵ��������͸��ؾ���
float fP_SR=3 ,fI_SR= 1; //����ֻ�õ�PI�������ɵ��������͸��ؾ���

//int demo[4];


int SpeedInnerControl_SL(int nPulse,int nTarget)//�ٶ��ڻ�����
{
	int nError_SL;//ƫ��
	
	
	
	nError_SL = nTarget - nPulse;//ƫ�� = Ŀ���ٶ� - ʵ���ٶ�
	nPwmBais_SL = fP_SL * (nError_SL - nErrorPrev_SL) + fI_SL * nError_SL;//����ʽPI������
	nErrorPrev_SL = nError_SL;//������һ��ƫ��
	nPwm_SL += nPwmBais_SL;//�������
	
	
	
	if(nPwm_SL > 50) nPwm_SL = 50;//�������ޣ���ֹ����PWM����
	if(nPwm_SL <-50) nPwm_SL =-50;
	
//	OutData[0]=(float)nPulse;//�ٶ�ʵ��ֵ
//	OutData[1]=(float)nTarget ;//PID�ٶȴ���ֵ
	return nPwm_SL;//�������ֵ
}
int SpeedInnerControl_SR(int nPulse,int nTarget)//�ٶ��ڻ�����
{
	int nError_SR;//ƫ��
	
	
	
	nError_SR = nTarget - nPulse;//ƫ�� = Ŀ���ٶ� - ʵ���ٶ�
	nPwmBais_SR = fP_SR * (nError_SR - nErrorPrev_SR) + fI_SR * nError_SR;//����ʽPI������
	aa[1]=nError_SR;
	aa[2]=fP_SR * (nError_SR - nErrorPrev_SR);
	
	nErrorPrev_SR = nError_SR;//������һ��ƫ��
	nPwm_SR += nPwmBais_SR;//�������
	if(nPwm_SR > 50) nPwm_SR = 50;//�������ޣ���ֹ����PWM����
	if(nPwm_SR <-50) nPwm_SR =-50;
	
//	OutData[0]=(float)nPulse;//�ٶ�ʵ��ֵ
//	OutData[1]=(float)nTarget ;//PID�ٶȴ���ֵ
	return nPwm_SR;//�������ֵ
}

int SpeedInnerControl_XL(int nPulse,int nTarget)//�ٶ��ڻ�����
{
	int nError_XL;//ƫ��
	
	
	
	nError_XL = nTarget - nPulse;//ƫ�� = Ŀ���ٶ� - ʵ���ٶ�
	nPwmBais_XL = fP_XL * (nError_XL - nErrorPrev_XL) + fI_XL * nError_XL;//����ʽPI������
	aa[3] = nError_XL;
	aa[4] = fP_XL * (nError_XL - nErrorPrev_XL);
	aa[5] = fI_XL * nError_XL;
	nErrorPrev_XL = nError_XL;//������һ��ƫ��
	nPwm_XL += nPwmBais_XL;//�������
	
	
	
	if(nPwm_XL > 50) nPwm_XL = 50;//�������ޣ���ֹ����PWM����
	if(nPwm_XL <-50) nPwm_XL =-50;
	
//	OutData[0]=(float)nPulse;//�ٶ�ʵ��ֵ
//	OutData[1]=(float)nTarget ;//PID�ٶȴ���ֵ
	return nPwm_XL;//�������ֵ
}

int SpeedInnerControl_XR(int nPulse,int nTarget)//�ٶ��ڻ�����
{
	int nError_XR;//ƫ��
	
	
	
	nError_XR = nTarget - nPulse;//ƫ�� = Ŀ���ٶ� - ʵ���ٶ�
//	demo[0] = nError_XR;
	nPwmBais_XR = fP_XR * (nError_XR - nErrorPrev_XR) + fI_XR * nError_XR;//����ʽPI������
//	demo[1] = fP_XR * (nError_XR - nErrorPrev_XR);
	nErrorPrev_XR = nError_XR;//������һ��ƫ��
	nPwm_XR += nPwmBais_XR;//�������
//	demo[2] = nPwm_XR;
	
	
	
	if(nPwm_XR > 50) nPwm_XR = 50;//�������ޣ���ֹ����PWM����
	if(nPwm_XR <-50) nPwm_XR =-50;
	
//	OutData[0]=(float)nPulse;//�ٶ�ʵ��ֵ
//	OutData[1]=(float)nTarget ;//PID�ٶȴ���ֵ
	return nPwm_XR;//�������ֵ
}




/****************************************
��������Machinery_all()
���ã�ͨ��pid�������;
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
	SetMotorVoltageAndDirection_SR(g_n_S_RightMotorOutput);//���õ����ѹ�ͷ���
	SetMotorVoltageAndDirection_SL(g_n_S_LeftMotorOutput);//���õ����ѹ�ͷ���
	SetMotorVoltageAndDirection_XR(g_n_X_RightMotorOutput);//���õ����ѹ�ͷ���
	SetMotorVoltageAndDirection_XL(g_n_X_LeftMotorOutput);//���õ����ѹ�ͷ���	

}
	


