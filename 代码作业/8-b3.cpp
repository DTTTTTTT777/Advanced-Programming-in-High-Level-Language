/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
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
struct KFC list[30];
struct SPECIAL special[10];
const char title[] = "KFC 2022冬季菜单";
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
	cout << setfill('=') << setw(LEN) << "=" << endl;
	cout << setfill(' ') << setw(LEN / 2 + tj_strlen(title) / 2) << title << endl;
	cout << setfill('=') << setw(LEN) << "=" << endl;
	cout << setfill(' ');
	for (int i = 0;list[i].ch != '\0';++i)
	{
		cout << setiosflags(ios::left);
		cout << " " << list[i].ch << " ";
		cout << setw(20) << list[i].name;
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
	if (special[0].name == NULL)
		return;
	cout << endl << "【输入规则说明】：" << endl;
	cout << special[0].type<<"=";
	sol(special[0].type, 0);
	cout << endl << "单独输入0则退出程序" << endl;
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
		for (int j = 0;list[j].ch != '\0';++j)
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

void input_from_file() 
{
	ifstream fin("KFC-price.cfg");
	if (!fin.is_open()) {
		cout << "文件KFC-price.cfg打开失败！" << endl;
		exit(-1);
	}

	char s[500], ch;
	bool tag = 0;
	int cnt_list = 0, cnt_special = 0;
	while (1) {  //首先输入单品菜单
		if (!fin.good()) {
			fin.clear();
			fin.ignore(INT_MAX, '\n');
			continue;
		}
		fin >> ch;
		if (ch == '#') {
			fin.getline(s, '\n');
			continue;
		}
		fin.putback(ch);
		fin >> s;
		//cout << "#" << s << endl;
		if (strcmp(s, "[单品菜单]") == 0) {
			tag = 1;
			//cout << "$$" << endl;
			continue;
		}
		if (!tag) {
			fin.getline(s, '\n');
			continue;
		}
		if (strcmp(s, "[组合菜单]") == 0)
			break;

		int len = strlen(s);
		for (int i = 0;i < len;++i)
			fin.putback(s[i]);

		fin >> list[cnt_list].ch >> list[cnt_list].name >> list[cnt_list].price;
		++cnt_list;
	}
	list[cnt_list] = { '\0',NULL,0 };

	while (!fin.eof()) {
		if (!fin.good()) {
			fin.clear();
			fin.ignore(INT_MAX, '\n');
			continue;
		}
		fin >> ch;
		//cout << ch << endl;
		if (ch == '#') {
			fin.getline(s, '\n');
			//cout << s << endl;
			continue;
		}
		fin.putback(ch);
		fin >> special[cnt_special].type >> special[cnt_special].name >> special[cnt_special].price;
		++cnt_special;
	}

	//cout << cnt_special << endl;
	//return 0;
	special[--cnt_special] = { NULL,NULL,0 };

	fin.close();

}
void sort_list()
{
	int n = 0;
	while (list[n].ch != '\0')
		++n;
	for (int k = 1;k < n;++k)
		for (int i = 0;i < n - k;++i)
			if (list[i].ch > list[i + 1].ch)
				swap(list[i], list[i + 1]);
}
int main()
{
	
	input_from_file();
	sort_list();

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
		sol(order, 1);
		char ch = getchar();
	}
	return 0;
}