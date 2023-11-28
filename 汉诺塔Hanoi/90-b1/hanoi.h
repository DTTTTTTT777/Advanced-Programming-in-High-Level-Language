/*2152402 ��� ������*/
#pragma once
using namespace std;
/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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