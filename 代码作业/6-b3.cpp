/*2152402 ��� ������*/
#include<iostream>
using namespace std;

int main()
{
	char str[33];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;

	unsigned int ans = 0;
	char* p;
	for (p = str;*p != '\0';++p)
		ans = ans * 2 + *p - '0';

	cout << ans << endl;

	return 0;
}
/*
11111111111111111111111111111111
10010110010111
*/