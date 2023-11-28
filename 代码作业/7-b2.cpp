/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include <Windows.h>
using namespace std;
struct KFC
{
	char ch;
	char name[20];
	double price;
};
struct SPECIAL
{
	char type[20];
	char name[40];
	double price;
};
const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
		{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		//{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};
const char title[] = "KFC 2021�＾�˵�";
int tj_strlen(const char* str)
{
	if (str == NULL)
		return 0;
	const char* p = str;
	for (;*p != '\0';++p)
		;
	return p - str;
}
void sol(const char* order, bool calc);
void menu()
{
	system("cls");
	system("mode con cols=120 lines=35"); //35 �� 120 �� 
	const int LEN = 61;
	cout << setfill('=') << setw(LEN) << "="<<endl;
	cout << setfill(' ') << setw(LEN / 2 + tj_strlen(title) / 2) << title << endl;
	cout << setfill('=') << setw(LEN) << "=" << endl;
	cout << setfill(' ');
	for (int i = 0;list[i].ch != '\0';++i)
	{
		cout << setiosflags(ios::left);
		cout << " " << list[i].ch << " ";
		cout<< setw(20) << list[i].name;
		cout << setw(7) << list[i].price;
		if (i % 2 == 0)
			cout << "|  ";
		else
			cout << endl;
	}
	cout << endl << "���Ż���Ϣ����" << endl;
	for (int i = 0;tj_strlen(special[i].type);++i)
	{
		cout << special[i].name << "=";
		int cnt = 1;
		for (int j = 0;special[i].type[j] != '\0';++j)
		{
			if (special[i].type[j] == special[i].type[j + 1])
			{
				++cnt;
				continue;
			}
			for (int k = 0;list[k].ch != '\0';++k)
				if (special[i].type[j] == list[k].ch)
				{
					cout << list[k].name << "*" << cnt;
					break;
				}
			cnt = 1;
		}
		cout << "=" << special[i].price << endl;
	}
	cout << endl << "���������˵������" << endl;
	cout << "ANV=";
	sol("ANV", 0);
	cout << " / " << "akaak=";
	sol("AKAAK", 0);
	cout << endl << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
}
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//ȡ��׼����豸��Ӧ�ľ��
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//ȡ��׼�����豸��Ӧ�ľ��
void cct_gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}
void cct_getxy(int& x, int& y)
{
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(__hout, &binfo);

	x = binfo.dwCursorPosition.X;
	y = binfo.dwCursorPosition.Y;

	return;
}
void sol(const char* order, bool calc)
{
	int num[30];
	double money = 0;
	for (int i = 0;i < 30;++i)
		num[i] = 0;
	for (int i = 0;order[i] != '\n' && order[i] != '\0';++i)
	{
		bool tag = 0;
		for(int j=0;list[j].ch!='\0';++j)
			if (list[j].ch == order[i])
			{
				tag = 1;
				++num[j];
			}
		if (!tag)
		{
			cout << "������󣬰����������." << endl;
			return;
		}
	}
	bool tag = 0;
	if (calc)
		cout << "���ĵ��=";
	for (int i = 0;list[i].ch != '\0';++i)
		if (num[i])
		{
			if (!tag)
				tag = 1;
			else
				cout << "+";
			cout << list[i].name << "*" << num[i];
		}
	if (!calc)
		return;
	for (int i = 0;tj_strlen(special[i].type);++i)
	{
		tag = 1;
		int cnt = 1;
		for (int j = 0;special[i].type[j] != '\0';++j)
		{
			if (special[i].type[j] == special[i].type[j + 1])
			{
				++cnt;
				continue;
			}
			for (int k = 0;list[k].ch != '\0';++k)
				if (special[i].type[j] == list[k].ch)
				{
					if (num[k] < cnt)
						tag = 0;
					break;
				}
			cnt = 1;
			if (!tag)
				break;
		}
		if (tag)
		{
			cnt = 1;
			for (int j = 0;special[i].type[j] != '\0';++j)
			{
				if (special[i].type[j] == special[i].type[j + 1])
				{
					++cnt;
					continue;
				}
				for (int k = 0;list[k].ch != '\0';++k)
					if (special[i].type[j] == list[k].ch)
					{
						num[k] -= cnt;
						break;
					}
				cnt = 1;
			}
			money += special[i].price;
		}
	}
	for (int i = 0;list[i].ch != '\0';++i)
		money += num[i] * list[i].price;
	cout << endl << "���ƣ� " << money << "Ԫ" << endl;
	cout << "�㵥��ɣ������������." << endl;
}
int main()
{
	while (1)
	{
		menu();
		cout << endl << "��㵥�� ";
		int X, Y;
		cct_getxy(X, Y);
		char order[100];
		fgets(order, 99, stdin);
		if (tj_strlen(order) == 2 && order[0] == '0')
			break;
		for (int i = 0;i < tj_strlen(order);++i)
			if (order[i] >= 'a' && order[i] <= 'z')
				order[i] -= 32;
		sol(order, 1);
		char ch = getchar();
	}
	return 0;
}