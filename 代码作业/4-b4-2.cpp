/*2152402 ��� ������*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ���ʾ��ʼ�˵�
  �����������
  �� �� ֵ��char op �˵�ѡ����
***************************************************************************/
char menu() 
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6] ";
	char op = _getche();
	return op;
}

/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ���I��J��K��L�����ƹ�����������ƶ�
  ���������HANDLE hout ����豸���
		  bool is_round �Ƿ���Ҫ�߽����
  �� �� ֵ����
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
			cout << "��Ϸ���������س������ز˵�.";
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
  �������ƣ�Move_by_ijkl
  ��    �ܣ���I��J��K��L�����ƹ�����������ƶ� (�����ͷ���������ƶ�)
  ���������HANDLE hout ����豸���
		  bool is_round �Ƿ���Ҫ�߽����
  �� �� ֵ����
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
				cout << "��Ϸ���������س������ز˵�.";
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
  �������ƣ�move_by_arrow
  ��    �ܣ��ü�ͷ�����ƹ�����������ƶ�
  ���������HANDLE hout ����豸���
		  bool is_round �Ƿ���Ҫ�߽����
  �� �� ֵ����
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
				cout << "��Ϸ���������س������ز˵�.";
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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
* 1. �˵��� 1/2 ���У������ͷ������ʹ��������ƶ�����ĳ����ܷ����ִ����⣿��������֣�
�������������ԭ��Ľ��͡�
	���������ͷʱ�������������� ��int op=_getch() ���ȶ���224���ٶ���75����75����ĸK��ASCII�룬���Թ��������ƶ���

*2. ��������Ĳ��ֳ����У�����"*"��ɵĿ���������� 20 ����ĸ�Ĵ���Σ�ÿ��������ɺ�
һ�����ڿ������� 20 ����ĸ����û�п��ܲ��� 20 ����ĸ��Ϊʲô��
	�п��ܲ���20����ĸ��
	���������������ɵ�������ͬ�����һ�ε������ĸ�Ḳ��ǰһ�εģ�������������������ĸ��С��20
*/