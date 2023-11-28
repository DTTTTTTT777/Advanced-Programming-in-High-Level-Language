/*2152402 软件 段婷婷*/
//主函数及菜单部分函数（需要提交）
#include<iostream>
#include<conio.h>
#include<windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

int menu()
{
	cct_cls();
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setfontsize("点阵字体", 20, 10);
	cout << "---------------------------------" << endl;
	cout << "1.内部数组，随机生成初始5个球" << endl;
	cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "5.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图形界面完整版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择]: ";
	char c = _getch();
	while (c < '0' || c > '9')
		c = _getch();
	return c - '0';
}

int main()
{
	srand(unsigned(time(NULL)));
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1){
		int opt = menu();
		cout << opt << endl;
		Sleep(10);
		if (opt == 0)
			break;
		else if (opt == 1)
			sol_for_opt1();
		else if (opt == 2)
			sol_for_opt2();
		else if (opt == 3)
			basic_solution();
		else if (opt == 4)
			draw_for_opt4();
		else if (opt == 5)
			draw_for_opt5();
		else if (opt == 6)
			draw_for_opt6();
		else if (opt == 7)
			complete_solution();
	}
}