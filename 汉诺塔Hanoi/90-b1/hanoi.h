/*2152402 软件 段婷婷*/
#pragma once
using namespace std;
/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int menu();

void sol_for_123(int opt);
void sol_for_opt4();
void draw_for_opt5();
void draw_for_opt6();
void draw_for_opt7();
void draw_for_opt8();
void draw_for_opt9();

void init_input(int& n, char& src, char& dst, char& tmp, bool delay);
void Pause(int y);
void go_to_next_step(bool enter);

void show_array_transverse();
void show_array_portrait(int Y);
void show_arrays(char src, char dst, int x, int y);

void draw_cylinder();
void draw_src_plates(char src, int n);
void init_graph(int n, char src, char dst, bool show_delay);
void draw_move(int n, char src, char dst);

void hanoi_output_move(int n, char src, char dst, int opt);
void hanoi(int n, char src, char tmp, char dst, int opt);