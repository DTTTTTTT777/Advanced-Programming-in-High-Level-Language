/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

const char chnstr[] = "��Ҽ��������½��ƾ�";
char result[256];

int main()
{
	double rmb, trmb;
	int tmp, val, idx = 0;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	//flag1���Ƿ��Ѿ����ֵ�һ��������   flag2: �ڳ����˵�һ��������������£�ǰ���Ƿ��л�δ������� flag3����ǰ�����Ƿ�����˷���

	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &rmb);
	rmb += 0.001;

	//��һ���֣�ʮ�ڡ���-------------------------------------------------------------------------
	//ʮ�ڣ�
	tmp = (int)(rmb / 1000000000);
	val = tmp;
	if (val >= 1 && val <= 9)
	{
		result[idx++] = chnstr[val << 1];
		result[idx++] = chnstr[(val << 1) + 1];
	}
	if (val != 0)
	{
		strcat(result, "ʰ");
		idx += 2;
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
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (flag1)
	{
		strcat(result, "��");
		idx += 2;
	}

	//ǧ�򡢰���ʮ����--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = (int)(rmb / 100000000);
	val = (int)(rmb - tmp * 100000000.0) / 10000000;
	if (val >= 1 && val <= 9)
	{
		result[idx++] = chnstr[val << 1];
		result[idx++] = chnstr[(val << 1) + 1];
	}
	if (val != 0)
	{
		strcat(result, "Ǫ");
		idx += 2;
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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;

		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (val != 0)
	{
		strcat(result, "��");
		idx += 2;
	}

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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (val != 0)
	{
		strcat(result, "ʰ");
		idx += 2;
	}

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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (flag3)
	{
		strcat(result, "��");
		idx += 2;
	}

	//ǧ���١�ʮ��Ԫ------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = (int)(rmb / 10000);
	val = (int)(rmb - tmp * 10000.0) / 1000;
	if (val >= 1 && val <= 9)
	{
		result[idx++] = chnstr[val << 1];
		result[idx++] = chnstr[(val << 1) + 1];
	}
	if (val != 0)
	{
		strcat(result, "Ǫ");
		idx += 2;
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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (val != 0)
	{
		strcat(result, "��");
		idx += 2;
	}
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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (val != 0)
	{
		strcat(result, "ʰ");
		idx += 2;
	}
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
			result[idx++] = chnstr[0];
			result[idx++] = chnstr[1];
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result[idx++] = chnstr[val << 1];
			result[idx++] = chnstr[(val << 1) + 1];
		}
	}
	if (flag1)
	{
		strcat(result, "Բ");
		idx += 2;
	}

	//�ǡ���--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //��/������ֵ  (������
	//�ǣ�
	trmb -= (int)(trmb);
	trmb *= 10;
	val = (int)(trmb);
	if (val >= 1 && val <= 9)
	{
		result[idx++] = chnstr[val << 1];
		result[idx++] = chnstr[(val << 1) + 1];
	}
	if (val != 0)
	{
		strcat(result, "��");
		idx += 2;
		flag1 = 1;
		flag3 = 1;
	}
	//�֣�
	trmb -= (int)(trmb);
	trmb *= 10;
	val = (int)(trmb);
	if (val != 0 && !flag3 && flag1)
	{
		result[idx++] = chnstr[0];
		result[idx++] = chnstr[1];
	}
	flag3 = 0;
	if (val >= 1 && val <= 9)
	{
		result[idx++] = chnstr[val << 1];
		result[idx++] = chnstr[(val << 1) + 1];
	}
	if (val != 0)
	{
		strcat(result, "��");
		idx += 2;
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
	{
		result[idx++] = chnstr[0];
		result[idx++] = chnstr[1];
		strcat(result, "Բ");
		idx += 2;
		strcat(result, "��");
		idx += 2;
	}
	else if (!flag3)
	{
		strcat(result, "��");
		idx += 2;
	}
	result[idx] = '\0';
	printf("��д�����:\n");
	printf("%s\n", result);
	return 0;
}