/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double rmb, trmb;
	int tmp, val;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	//flag1���Ƿ��Ѿ����ֵ�һ��������   flag2: �ڳ����˵�һ��������������£�ǰ���Ƿ��л�δ������� flag3����ǰ�����Ƿ�����˷���

	cout << "������[0-100��)֮�������:" << endl;
	cin >> rmb;
	rmb += 0.001;
	cout << "��д�����:" << endl;

	//��һ���֣�ʮ�ڡ���-------------------------------------------------------------------------
	//ʮ�ڣ�
	tmp = int(rmb / 1000000000);
	val = tmp;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "ʰ";
		flag1 = 1;
	}

	//�ڣ�
	val = int(rmb - tmp * 1000000000.0) / 100000000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag1)
		cout << "��";

	//ǧ�򡢰���ʮ����--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = int(rmb / 100000000);
	val = int(rmb - tmp * 100000000.0) / 10000000;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "Ǫ";
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//����
	tmp = int(rmb / 10000000);
	val = int(rmb - tmp * 10000000.0) / 1000000;
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;

		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "��";

	//ʮ��
	tmp = int(rmb / 1000000);
	val = int(rmb - tmp * 1000000.0) / 100000;
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "ʰ";

	//��
	tmp = int(rmb / 100000);
	val = int(rmb - tmp * 100000.0) / 10000;
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag3)
		cout << "��";

	//ǧ���١�ʮ��Ԫ------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = int(rmb / 10000);
	val = int(rmb - tmp * 10000.0) / 1000;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "Ǫ";
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//�٣�
	tmp = int(rmb / 1000);
	val = int(rmb - tmp * 1000.0) / 100;
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "��";
	//cout << flag1 << flag2;
	//ʮ��
	tmp = int(rmb / 100);
	val = int(rmb - tmp * 100.0) / 10;
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "ʰ";
	//Ԫ��
	trmb = rmb - tmp * 100.0;
	tmp = int(trmb / 10);
	val = int(trmb - tmp * 10.0);
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
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag1)
		cout << "Բ";

	//�ǡ���--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //��/������ֵ  (������
	//�ǣ�
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "��";
		flag1 = 1;
		flag3 = 1;
	}
	//�֣�
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val != 0 && !flag3 && flag1)
		daxie(0,1);
	flag3 = 0;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "��";
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
	{
		daxie(0, 1);
		cout << "Բ��";
	}
	else if (!flag3)
		cout << "��";
	cout << endl;
	return 0;
}