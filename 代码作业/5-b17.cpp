/*2152402 ��� ������*/
#include<iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?"; //�� 15 ��Ӣ�ķ��� 

char get_random_c(int type)
{
	if (type == 0) //��д��ĸ
		return rand() % 26 + 'A';
	if (type == 1) //Сд��ĸ
		return rand() % 26 + 'a';
	if (type == 2) //����
		return rand() % 10 + '0';
	return other[rand() % 15];
}

int main()
{
	int len, num[4], totnum = 0;

	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len;

	if (!cin.good())
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	for (int i = 0;i < 4;++i)
	{
		cin >> num[i];
		if (!cin.good())
		{
			cout << "����Ƿ�" << endl;
			return 0;
		}
		totnum += num[i];
	}
	if (len < 12 || len>16)
	{
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (num[0] < 2 || num[0] > len)
	{
		cout << "��д��ĸ����[" << num[0] << "]����ȷ" << endl;
		return 0;
	}
	if (num[1] < 2 || num[1] > len)
	{
		cout << "Сд��ĸ����[" << num[1] << "]����ȷ" << endl;
		return 0;
	}
	if (num[2] < 2 || num[2] > len)
	{
		cout << "���ָ���[" << num[2] << "]����ȷ" << endl;
		return 0;
	}
	if (num[3] < 2 || num[3] > len)
	{
		cout << "�������Ÿ���[" << num[3] << "]����ȷ" << endl;
		return 0;
	}
	if (totnum > len)
	{
		cout << "�����ַ�����֮��[" << num[0] << "+" << num[1] << "+" << num[2] << "+" << num[3] << "]���������볤��[" << len << "]" << endl;
		return 0;
	}

	cout << len << " ";
	for (int i = 0;i < 4;++i)
		cout << num[i] << " ";
	cout << endl;

	char code[16];
	bool vis[16];
	srand(1233);
	
	int T = 10;
	while (T--)
	{
		for (int i = 0;i < len;++i)
			vis[i] = 0;
		for (int i = 0;i < 4;++i)
		{
			int cur = 0;
			while (cur < num[i])
			{
				int idx = rand() % len;
				if (vis[idx])
					continue;
				vis[idx] = 1;
				code[idx] = get_random_c(i);
				++cur;
			}
		}
		for (int i = 0;i < len;++i)
			if (!vis[i])
				code[i] = get_random_c(rand() % 4);
		for (int i = 0;i < len;++i)
			cout << code[i];
		cout << endl;
	}

	return 0;
}
/*
a

0
a

20 2 2 3 3

12 a 1 3 4

12 10 0 10 10

12 5 5 5 5

16 2 4 5 6a

16 2a 4 5 6
*/