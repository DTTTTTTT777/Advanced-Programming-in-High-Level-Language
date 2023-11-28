/*2152402 软件 段婷婷*/
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
	{'A', "香辣鸡腿堡",         18.5},
	{'B', "劲脆鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "劲爆鸡米花",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "藤椒无骨大鸡柳(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "香甜粟米棒",         9.0},
	{'U', "葡式蛋挞",           8.0},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
		{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		//{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
		{NULL, NULL, 0}
};
const char title[] = "KFC 2021秋季菜单";
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
	system("mode con cols=120 lines=35"); //35 行 120 列 
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
	cout << endl << "【优惠信息】：" << endl;
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
	cout << endl << "【输入规则说明】：" << endl;
	cout << "ANV=";
	sol("ANV", 0);
	cout << " / " << "akaak=";
	sol("AKAAK", 0);
	cout << endl << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
}
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//取标准输出设备对应的句柄
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//取标准输入设备对应的句柄
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
			cout << "输入错误，按任意键继续." << endl;
			return;
		}
	}
	bool tag = 0;
	if (calc)
		cout << "您的点餐=";
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
	cout << endl << "共计： " << money << "元" << endl;
	cout << "点单完成，按任意键继续." << endl;
}
int main()
{
	while (1)
	{
		menu();
		cout << endl << "请点单： ";
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