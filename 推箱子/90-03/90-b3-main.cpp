/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<io.h>
#include<string.h>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

int menu() //显示主菜单并返回用户选择
{
	cct_cls();
	cct_setconsoleborder(130, 48, 130, 48);
	cout << "------------------------------" << endl;
	cout << "1.显示关卡" << endl;
	cout << "0.退出" << endl;
	cout << "------------------------------" << endl;
	cout << "[请选择0-1] ";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == '0' || ch == '1')
			break;
	}
	cout << ch;
	return ch - '0';
}



int main()
{
	if (!open_stage()) {
		cout << "无法打开[.\stage\]目录." << endl;
		return 0;
	}
	while (1) {
		if (menu() == 0)
			break;
		int ret = read_stage();
		if (ret != 1) {
			cct_cls();
			cct_gotoxy(0, 1);
			cout << "无法找到任何关卡文件";
            wait_for_end();
		}
        cct_gotoxy(0, 45);
        cout << "本小题结束，请输出End继续..";
	}
    cct_gotoxy(0, 40);
    return 0;
}