/*2152402 软件 段婷婷*/
#include<iostream>
using namespace std;
int main()
{
	int mt[9][9];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
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
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				if (mt[i][j] >= 1 && mt[i][j] <= 9)
					break;
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
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
				cout << "不是数独的解" << endl;
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
				cout << "不是数独的解" << endl;
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
						cout << "不是数独的解" << endl;
						return 0;
					}
					vis[mt[i][j]] = 1;
				}
		}
	cout << "是数独的解" << endl;
	return 0;
}