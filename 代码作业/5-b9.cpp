/*2152402 ��� ������*/
#include<iostream>
using namespace std;
int main()
{
	int mt[9][9];
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0;i < 9;++i)
		for (int j = 0;j < 9;++j)
		{
			while (1)
			{
				cin >> mt[i][j];
				if (!cin.good())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				if (mt[i][j] >= 1 && mt[i][j] <= 9)
					break;
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
			}
		}

	bool vis[10];

	for (int i = 0;i < 9;++i)
	{
		bool tag = 1;
		for (int j = 0;j < 10;++j)
			vis[j] = 0;
		for (int j = 0;j < 9;++j)
		{
			if (vis[mt[i][j]])
			{
				cout << "���������Ľ�" << endl;
				return 0;
			}
			vis[mt[i][j]] = 1;
		}
	}
	for (int j = 0;j < 9;++j)
	{
		for (int i = 0;i < 10;++i)
			vis[i] = 0;
		for (int i = 0;i < 9;++i)
		{
			if (vis[mt[i][j]])
			{
				cout << "���������Ľ�" << endl;
				return 0;
			}
			vis[mt[i][j]] = 1;
		}
	}
	for (int k1 = 0;k1 < 3;++k1)
		for (int k2 = 0;k2 < 3;++k2)
		{
			for (int i = 0;i < 10;++i)
				vis[i] = 0;
			int begi = k1 * 3, begj = k2 * 3;
			for (int i = begi;i < begi + 3;++i)
				for (int j = begj;j < begj + 3;++j)
				{
					if (vis[mt[i][j]])
					{
						cout << "���������Ľ�" << endl;
						return 0;
					}
					vis[mt[i][j]] = 1;
				}
		}
	cout << "�������Ľ�" << endl;
	return 0;
}