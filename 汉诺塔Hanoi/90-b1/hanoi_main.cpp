/*2152402 软件 段婷婷*/
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <iostream>
using namespace std;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
		int opt = menu();
		if (opt == 0)
			break;
		if (opt >= 1 && opt <= 9)
			cout << opt << endl << endl << endl;
		if (opt >= 1 && opt <= 3)
			sol_for_123(opt);
		else if (opt == 4)
			sol_for_opt4();
		else if (opt == 5)
			draw_for_opt5();
		else if (opt == 6)
			draw_for_opt6();
		else if (opt == 7)
			draw_for_opt7();
		else if (opt == 8)
			draw_for_opt8();
		else if(opt==9)
			draw_for_opt9();
	}
	return 0;
}