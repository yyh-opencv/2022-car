#include "tim.h"//����timͷ�ļ�
#include "encoder.h"
int iTim1Encoder;//��Ŵ�TIM1��ʱ���������ı���������   ����
int iTim4Encoder;//��Ŵ�TIM4��ʱ���������ı���������		����
int iTim5Encoder;//��Ŵ�TIM5��ʱ���������ı���������		����
int iTim8Encoder;//��Ŵ�TIM8��ʱ���������ı���������		����


int Tim1Encoder;//  ����
int Tim4Encoder;//	����
int Tim5Encoder;//	����
int Tim8Encoder;//  ����

MotoData Moto_1;
MotoData Moto_2;
MotoData Moto_3;
MotoData Moto_4;




/*************************************************************

��������GetTim1Encoder();
				GetTim4Encoder();
				GetTim5Encoder();
				GetTim8Encoder();

���ã���ȡ���ñ�������ȡ��� 
14ms������
**************************************************************/

int GetTim1Encoder(void)//��ȡTIM1��ʱ���������ı���������
{
	iTim1Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim1));//�ȶ�ȡ������
  	__HAL_TIM_SET_COUNTER(&htim1,0);//�ټ���������
	return -iTim1Encoder;//����������
}
int GetTim4Encoder(void)//��ȡTIM4��ʱ���������ı���������
{
	iTim4Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim4));//�ȶ�ȡ������
	__HAL_TIM_SET_COUNTER(&htim4,0);//�ټ���������
	return iTim4Encoder;//����������
}

int GetTim5Encoder(void)//��ȡTIM5��ʱ���������ı���������
{
	iTim5Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim5));//�ȶ�ȡ������
	__HAL_TIM_SET_COUNTER(&htim5,0);//�ټ���������
	return iTim5Encoder;//����������
}

int GetTim8Encoder(void)//��ȡTIM8��ʱ���������ı���������
{
	iTim8Encoder = (short)(__HAL_TIM_GET_COUNTER(&htim8));//�ȶ�ȡ������
	__HAL_TIM_SET_COUNTER(&htim8,0);//�ټ���������
	return -iTim8Encoder;//����������
}



/************************************
������:SetMotorVoltageAndDirection()
��Ҫת���ĳ�����int Tem3Encoder_R;  
								int Tem2Encoder_L;
���ã�����ת������ת��Ϊ��������ͨ��PID
����ռ�ձȵ��ڡ���Ϊռ�ձ�ֻ��������
************************************/
void SetMotorVoltageAndDirection_SR(int nMotorPwm)//���õ����ѹ�ͷ���
{
	
	if(nMotorPwm < 0)//��ת
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�
		nMotorPwm = (-nMotorPwm);//�������ֵ�Ǹ�ֵ����ȡ����������ΪPWM�Ĵ���ֻ������ֵ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�?
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, nMotorPwm);
	}

}
void SetMotorVoltageAndDirection_SL(int nMotorPwm)//���õ����ѹ�ͷ���
{
	
	if(nMotorPwm < 0)//��ת
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�ƽ
		nMotorPwm = (-nMotorPwm);//�������ֵ�Ǹ�ֵ����ȡ����������ΪPWM�Ĵ���ֻ������ֵ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�ƽ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, nMotorPwm);
	}

}

void SetMotorVoltageAndDirection_XL(int nMotorPwm)//���õ����ѹ�ͷ���
{
	
	if(nMotorPwm < 0)//��ת
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�ƽ
		nMotorPwm = (-nMotorPwm);//�������ֵ�Ǹ�ֵ����ȡ����������ΪPWM�Ĵ���ֻ������ֵ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, nMotorPwm);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);//��ʼ��BIN2����Ϊ�ߵ�ƽ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, nMotorPwm);
	}

}
void SetMotorVoltageAndDirection_XR(int nMotorPwm)//���õ����ѹ�ͷ���
{
	
	if(nMotorPwm < 0)//��ת
	{
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);//��ʼ��BIN1����Ϊ�͵�ƽ
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);//��ʼ��BIN2����Ϊ�ߵ�ƽ
		nMotorPwm = (-nMotorPwm);//�������ֵ�Ǹ�ֵ����ȡ����������ΪPWM�Ĵ���ֻ������ֵ
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, nMotorPwm);
	}
	else
	{
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);//��ʼ��BIN1����Ϊ�ߵ�ƽ
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);//��ʼ��BIN2����Ϊ�͵�?
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, nMotorPwm);
	}

}



/*************************************************************************************************************************************/
/*************************************************************

��������ALL_Encoder();
���ã��Ա���������������

**************************************************************/
void ALL_Encoder()
{
		Tim1Encoder=GetTim1Encoder();
		Tim4Encoder=GetTim4Encoder();
		Tim5Encoder=GetTim5Encoder();
		Tim8Encoder=GetTim8Encoder();
}


