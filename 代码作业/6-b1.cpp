/*2152402 ��� ������*/
#include<iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);

	for (p = str, pa = a;*p != '\0' && pa - a < 10;++p)
		if (*p >= '0' && *p <= '9')
		{
			for (*pa = 0;*p >= '0' && *p <= '9';++p)
				*pa = (*pa) * 10 + *p - '0';
			++pa;
		}
	cout << "����" << (pa - a) / sizeof(char) << "������" << endl;
	for (pnum = a;pnum != pa;++pnum)
		cout << *pnum << " ";
	cout << endl;
	return 0;
}
/*
ad 23ewe adsfgt4gr 434erfd -908hj

1a2 cd3n4,,5ls;6 78;;8nds sasd9;;-134313eds we23ed 234c
*/