/*2152402 ��� ������*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];
	int cnt[5];
	for (int i = 0;i < 5;++i)
		cnt[i] = 0;

	cout << "�������1��" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "�������2��" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "�������3��" << endl;
	cin.getline(str[2], 128, '\n');

	for (int i = 0;i < 3;++i)
		for (int j = 0;str[i][j] != '\0';++j)
		{
			char ch = str[i][j];
			if (ch >= 'a' && ch <= 'z')
				++cnt[0];
			else if (ch >= 'A' && ch <= 'Z')
				++cnt[1];
			else if (ch >= '0' && ch <= '9')
				++cnt[2];
			else if (ch == ' ')
				++cnt[3];
			else
				++cnt[4];
		}

	cout << "��д : " << cnt[1] << endl;;
	cout << "Сд : " << cnt[0] << endl;
	cout << "���� : " << cnt[2] << endl;
	cout << "�ո� : " << cnt[3] << endl;
	cout << "���� : " << cnt[4] << endl;

	return 0;
}
/*
Welcome to Tongji University.
<Hello,world!> -> ��Hello��world����
Name=���� and No=2059999 && Sex=��
*/