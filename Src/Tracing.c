#include "Tracing.h"
#include "Machinery.h"
#include "tim.h"
/***************************
��������Tracing();
���ã�����Ѱ�죻���߻�1��������0;
***************************/
extern uint8_t Rx_dat;
extern int a;
void Tracing()
{	
	//�м���������������ֱ��
 if(((Left_3)==1)&&((Midlight)==1)&&((Right_3)==1))
	{
		g_nSpeedTarget_SL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR = 25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
	
	//Сƫ������С����
	else if(((Left_3)==0)&&((Midlight)==1)&&((Right_3)==1))
	{
		g_nSpeedTarget_SL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR =24;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = 25;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =24;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
	//Сƫ������С����
	else if(((Left_3)==1)&&((Midlight)==1)&&((Right_3)==0))
	{
		g_nSpeedTarget_SL = 24;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR = 25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = 24;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =25;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
	else if(((Left_3)==0)&&((Midlight)==0)&&((Right_3)==0)&&((Right_1)==0)&&((Left_1)==0))
	{
		g_nSpeedTarget_SL = 20;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR =20;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = 20;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =20;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
	

	else if(((((Left_1)==1)||((Left_2)==1))&&(Right_1)==0))
	{
		g_nSpeedTarget_SL = -20;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR = 40;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = -20;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =40;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
	else if(((((Right_1)==1)||((Right_2)==1))&&(Left_1)==0))
	{
		g_nSpeedTarget_SL = 40;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_SR = -20;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
		g_nSpeedTarget_XL = 40;//ȫ�ֱ������������ٶ�Ŀ��ֵ
		g_nSpeedTarget_XR =-20;//ȫ�ֱ��������ҵ���ٶ�Ŀ��ֵ
	}
}





