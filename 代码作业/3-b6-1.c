/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	double rmb, trmb;
	int tmp, val;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	//flag1���Ƿ��Ѿ����ֵ�һ��������   flag2: �ڳ����˵�һ��������������£�ǰ���Ƿ��л�δ������� flag3����ǰ�����Ƿ�����˷���

	printf("������[0-100 ��)֮�������:\n");
	scanf("%lf",&rmb);
	rmb += 0.001;

	//��һ���֣�ʮ�ڡ���-------------------------------------------------------------------------
	//ʮ�ڣ�
	tmp = (int)(rmb / 1000000000);
	val = tmp;
	if (val == 1)
		printf("Ҽ");
	else if (val == 2)
		printf("��");
	else if (val == 3)
		printf("��");
	else if (val == 4)
		printf("��");
	else if (val == 5)
		printf("��");
	else if (val == 6)
		printf("½");
	else if (val == 7)
		printf("��");
	else if (val == 8)
		printf("��");
	else if (val == 9)
		printf("��");
	if (val != 0)
	{
		printf("ʰ");
		flag1 = 1;
	}

	//�ڣ�
	val = (int)(rmb - tmp * 1000000000.0) / 100000000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (flag1)
		printf("��");

	//ǧ�򡢰���ʮ����--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = (int)(rmb / 100000000);
	val = (int)(rmb - tmp * 100000000.0) / 10000000;
	if (val == 1)
		printf("Ҽ");
	else if (val == 2)
		printf("��");
	else if (val == 3)
		printf("��");
	else if (val == 4)
		printf("��");
	else if (val == 5)
		printf("��");
	else if (val == 6)
		printf("½");
	else if (val == 7)
		printf("��");
	else if (val == 8)
		printf("��");
	else if (val == 9)
		printf("��");
	if (val != 0)
	{
		printf("Ǫ");
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//����
	tmp = (int)(rmb / 10000000);
	val = (int)(rmb - tmp * 10000000.0) / 1000000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;

		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (val != 0)
		printf("��");

	//ʮ��
	tmp = (int)(rmb / 1000000);
	val = (int)(rmb - tmp * 1000000.0) / 100000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (val != 0)
		printf("ʰ");

	//��
	tmp = (int)(rmb / 100000);
	val = (int)(rmb - tmp * 100000.0) / 10000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (flag3)
		printf("��");

	//ǧ���١�ʮ��Ԫ------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = (int)(rmb / 10000);
	val = (int)(rmb - tmp * 10000.0) / 1000;
	if (val == 1)
		printf("Ҽ");
	else if (val == 2)
		printf("��");
	else if (val == 3)
		printf("��");
	else if (val == 4)
		printf("��");
	else if (val == 5)
		printf("��");
	else if (val == 6)
		printf("½");
	else if (val == 7)
		printf("��");
	else if (val == 8)
		printf("��");
	else if (val == 9)
		printf("��");
	if (val != 0)
	{
		printf("Ǫ");
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//�٣�
	tmp = (int)(rmb / 1000);
	val = (int)(rmb - tmp * 1000.0) / 100;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (val != 0)
		printf("��");
	//printf(flag1 << flag2;
	//ʮ��
	tmp = (int)(rmb / 100);
	val = (int)(rmb - tmp * 100.0) / 10;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (val != 0)
		printf("ʰ");
	//Ԫ��
	trmb = rmb - tmp * 100.0;
	tmp = (int)(trmb / 10);
	val = (int)(trmb - tmp * 10.0);
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			printf("��");
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			printf("Ҽ");
		else if (val == 2)
			printf("��");
		else if (val == 3)
			printf("��");
		else if (val == 4)
			printf("��");
		else if (val == 5)
			printf("��");
		else if (val == 6)
			printf("½");
		else if (val == 7)
			printf("��");
		else if (val == 8)
			printf("��");
		else if (val == 9)
			printf("��");
	}
	if (flag1)
		printf("Բ");

	//�ǡ���--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //��/������ֵ  (������
	//�ǣ�
	trmb -= (int)(trmb);
	trmb *= 10;
	val = (int)(trmb);
	if (val == 1)
		printf("Ҽ");
	else if (val == 2)
		printf("��");
	else if (val == 3)
		printf("��");
	else if (val == 4)
		printf("��");
	else if (val == 5)
		printf("��");
	else if (val == 6)
		printf("½");
	else if (val == 7)
		printf("��");
	else if (val == 8)
		printf("��");
	else if (val == 9)
		printf("��");
	if (val != 0)
	{
		printf("��");
		flag1 = 1;
		flag3 = 1;
	}
	//�֣�
	trmb -= (int)(trmb);
	trmb *= 10;
	val = (int)(trmb);
	if (val != 0 && !flag3 && flag1)
		printf("��");
	flag3 = 0;
	if (val == 1)
		printf("Ҽ");
	else if (val == 2)
		printf("��");
	else if (val == 3)
		printf("��");
	else if (val == 4)
		printf("��");
	else if (val == 5)
		printf("��");
	else if (val == 6)
		printf("½");
	else if (val == 7)
		printf("��");
	else if (val == 8)
		printf("��");
	else if (val == 9)
		printf("��");
	if (val != 0)
	{
		printf("��");
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
		printf("��Բ��");
	else if (!flag3)
		printf("��");
	printf("\n");
	return 0;
}