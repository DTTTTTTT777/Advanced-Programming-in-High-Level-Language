/*2152402 ��� ������*/
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�";
string result;

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
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "ʰ";
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
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag1)
		result += "��";

	//ǧ�򡢰���ʮ����--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = int(rmb / 100000000);
	val = int(rmb - tmp * 100000000.0) / 10000000;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "Ǫ";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;

		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "��";

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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "ʰ";

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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag3)
		result += "��";

	//ǧ���١�ʮ��Ԫ------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//ǧ��
	tmp = int(rmb / 10000);
	val = int(rmb - tmp * 10000.0) / 1000;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "Ǫ";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "��";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "ʰ";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag1)
		result += "Բ";

	//�ǡ���--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //��/������ֵ  (������
	//�ǣ�
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "��";
		flag1 = 1;
		flag3 = 1;
	}
	//�֣�
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val != 0 && !flag3 && flag1)
	{
		result.push_back(chnstr[0]);
		result.push_back(chnstr[1]);
	}
	flag3 = 0;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "��";
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
	{
		result.push_back(chnstr[0]);
		result.push_back(chnstr[1]);
		result += "Բ��";
	}
	else if (!flag3)
		result += "��";
	cout << result << endl;
	return 0;
}