/*2152402 软件 段婷婷*/
#include<iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?"; //共 15 个英文符号 

char get_random_c(int type)
{
	if (type == 0) //大写字母
		return rand() % 26 + 'A';
	if (type == 1) //小写字母
		return rand() % 26 + 'a';
	if (type == 2) //数字
		return rand() % 10 + '0';
	return other[rand() % 15];
}

int main()
{
	int len, num[4], totnum = 0;

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len;

	if (!cin.good())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	for (int i = 0;i < 4;++i)
	{
		cin >> num[i];
		if (!cin.good())
		{
			cout << "输入非法" << endl;
			return 0;
		}
		totnum += num[i];
	}
	if (len < 12 || len>16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (num[0] < 2 || num[0] > len)
	{
		cout << "大写字母个数[" << num[0] << "]不正确" << endl;
		return 0;
	}
	if (num[1] < 2 || num[1] > len)
	{
		cout << "小写字母个数[" << num[1] << "]不正确" << endl;
		return 0;
	}
	if (num[2] < 2 || num[2] > len)
	{
		cout << "数字个数[" << num[2] << "]不正确" << endl;
		return 0;
	}
	if (num[3] < 2 || num[3] > len)
	{
		cout << "其它符号个数[" << num[3] << "]不正确" << endl;
		return 0;
	}
	if (totnum > len)
	{
		cout << "所有字符类型之和[" << num[0] << "+" << num[1] << "+" << num[2] << "+" << num[3] << "]大于总密码长度[" << len << "]" << endl;
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