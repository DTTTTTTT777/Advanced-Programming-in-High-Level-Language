/*2152402 ��� ������*/
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <iostream>
using namespace std;
/* ----------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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