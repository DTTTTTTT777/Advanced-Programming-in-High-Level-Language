/*2152402 软件 段婷婷*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：显示初始菜单
  输入参数：无
  返 回 值：char op 菜单选择结果
***************************************************************************/
char menu() 
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6] ";
	char op = _getche();
	return op;
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：用I、J、K、L键控制光标上下左右移动
  输入参数：HANDLE hout 输出设备句柄
		  bool is_round 是否需要边界回绕
  返 回 值：无
***************************************************************************/
void move_by_ijkl(const HANDLE hout, const bool is_round)
{
	cls(hout);
	init_border(hout);
	gotoxy(hout, (MAX_X + 1) / 2, (MAX_Y + 1) / 2);
	while (1)
	{
		int op = _getch();
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hout, &info);
		int X = info.dwCursorPosition.X, Y = info.dwCursorPosition.Y;
		if (op == 'I' || op == 'i')
		{
			int tY = Y - 1;
			if (tY < 1)
				if (is_round)
					tY = MAX_Y;
				else
					tY = 1;
			gotoxy(hout, X, tY);
		}
		else if (op == 'J' || op == 'j')
		{
			int tX = X - 1;
			if (tX < 1)
				if (is_round)
					tX = MAX_X;
				else
					tX = 1;
			gotoxy(hout, tX, Y);
		}
		else if (op == 'K' || op == 'k')
		{
			int tY = Y + 1;
			if (tY > MAX_Y)
				if (is_round)
					tY = 1;
				else
					tY = MAX_Y;
			gotoxy(hout, X, tY);
		}
		else if (op == 'L' || op == 'l')
		{
			int tX = X + 1;
			if (tX > MAX_X)
				if (is_round)
					tX = 1;
				else
					tX = MAX_X;
			gotoxy(hout, tX, Y);
		}
		else if (op == 32)
		{
			showch(hout, X, Y, ' ');
			gotoxy(hout, X , Y);
		}
		else if (op == 'Q' || op == 'q')
		{
			gotoxy(hout, 0, MAX_Y + 6);
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int op2 = _getch();
				if (op2 == 13)
					break;
			}
			break;
		}
	}
}
/***************************************************************************
  函数名称：Move_by_ijkl
  功    能：用I、J、K、L键控制光标上下左右移动 (按左箭头不会向下移动)
  输入参数：HANDLE hout 输出设备句柄
		  bool is_round 是否需要边界回绕
  返 回 值：无
***************************************************************************/
void Move_by_ijkl(const HANDLE hout, const bool is_round)
{
	cls(hout);
	init_border(hout);
	gotoxy(hout, (MAX_X + 1) / 2, (MAX_Y + 1) / 2);
	bool is_valid = 1;
	while (1)
	{
		if (_kbhit())
		{
			int op = _getch();
			if (op == 224)
			{
				is_valid = 0;
				continue;
			}
			if (!is_valid)
			{
				is_valid = 1;
				continue;
			}
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hout, &info);
			int X = info.dwCursorPosition.X, Y = info.dwCursorPosition.Y;
			if (op == 'I' || op == 'i')
			{
				int tY = Y - 1;
				if (tY < 1)
					if (is_round)
						tY = MAX_Y;
					else
						tY = 1;
				gotoxy(hout, X, tY);
			}
			else if (op == 'J' || op == 'j')
			{
				int tX = X - 1;
				if (tX < 1)
					if (is_round)
						tX = MAX_X;
					else
						tX = 1;
				gotoxy(hout, tX, Y);
			}
			else if (op == 'K' || op == 'k')
			{
				int tY = Y + 1;
				if (tY > MAX_Y)
					if (is_round)
						tY = 1;
					else
						tY = MAX_Y;
				gotoxy(hout, X, tY);
			}
			else if (op == 'L' || op == 'l')
			{
				int tX = X + 1;
				if (tX > MAX_X)
					if (is_round)
						tX = 1;
					else
						tX = MAX_X;
				gotoxy(hout, tX, Y);
			}
			else if (op == 32)
			{
				showch(hout, X, Y, ' ');
				gotoxy(hout, X, Y);
			}
			else if (op == 'Q' || op == 'q')
			{
				gotoxy(hout, 0, MAX_Y + 6);
				cout << "游戏结束，按回车键返回菜单.";
				while (1)
				{
					int op2 = _getch();
					if (op2 == 13)
						break;
				}
				break;
			}
		}
	}
}
/***************************************************************************
  函数名称：move_by_arrow
  功    能：用箭头键控制光标上下左右移动
  输入参数：HANDLE hout 输出设备句柄
		  bool is_round 是否需要边界回绕
  返 回 值：无
***************************************************************************/
void move_by_arrow(const HANDLE hout, const bool is_round)
{
	cls(hout);
	init_border(hout);
	gotoxy(hout, (MAX_X + 1) / 2, (MAX_Y + 1) / 2);
	bool is_valid = 0;
	while (1)
	{
		if (_kbhit())
		{
			int op = _getch();
			if (op == 224)
			{
				is_valid = 1;
				continue;
			}
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(hout, &info);
			int X = info.dwCursorPosition.X, Y = info.dwCursorPosition.Y;
			if (op == 'Q' || op == 'q')
			{
				gotoxy(hout, 0, MAX_Y + 6);
				cout << "游戏结束，按回车键返回菜单.";
				while (1)
				{
					int op2 = _getch();
					if (op2 == 13)
						break;
				}
				break;
			}
			else if (op == 32)
			{
				showch(hout, X, Y, ' ');
				gotoxy(hout, X, Y);
			}
			if (!is_valid)
				continue;
			is_valid = 0;
			if (op == 72)
			{
				int tY = Y - 1;
				if (tY < 1)
					if (is_round)
						tY = MAX_Y;
					else
						tY = 1;
				gotoxy(hout, X, tY);
			}
			else if (op == 75)
			{
				int tX = X - 1;
				if (tX < 1)
					if (is_round)
						tX = MAX_X;
					else
						tX = 1;
				gotoxy(hout, tX, Y);
			}
			else if (op == 80)
			{
				int tY = Y + 1;
				if (tY > MAX_Y)
					if (is_round)
						tY = 1;
					else
						tY = MAX_Y;
				gotoxy(hout, X, tY);
			}
			else if (op == 77)
			{
				int tX = X + 1;
				if (tX > MAX_X)
					if (is_round)
						tX = 1;
					else
						tX = MAX_X;
				gotoxy(hout, tX, Y);
			}
		}
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (1) 
	{
		cls(hout);
		char op = menu();
		if (op < '0' || op > '6') 
			continue;
		if (op == '0')
			break;
		if (op < '3')
			move_by_ijkl(hout, op == '2');
		else if (op < '5')
			move_by_arrow(hout, op == '4');
		else 
			Move_by_ijkl(hout, op == '6');
	}

	return 0;
}
/*
* 1. 菜单第 1/2 项中，按左箭头键可以使光标向下移动，你的程序能否重现此问题？如果能重现，
给出此问题产生原因的解释。
	当输入左箭头时，返回两个键码 ，int op=_getch() 会先读出224，再读出75，而75是字母K的ASCII码，所以光变会向下移动。

*2. 本题给出的部分程序中，有在"*"组成的框中随机生成 20 个字母的代码段，每次运行完成后，
一定能在框中生成 20 个字母吗？有没有可能不到 20 个字母？为什么？
	有可能不到20个字母。
	如果有两次随机生成的坐标相同，则后一次的输出字母会覆盖前一次的，这种情况下输出的总字母数小于20
*/