/*2152402 ��� ������*/
#include<iostream>

using namespace std;

int tj_strlen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}

int main()
{
	char str[80];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 80, stdin);

	int len = tj_strlen(str);
	char* p1 = str, * p2 = str + len - 1;
	if (*p2 == '\n')
		--p2;

	for (;p2 - p1 > 0;++p1, --p2)
		if (*p1 != *p2)
		{
			cout << "no" << endl;
			return 0;
		}
	cout << "yes" << endl;

	return 0;
}
/*
1234554321
abcdedcba
abcdeabcd
 ab ba 
 ab ba
*/