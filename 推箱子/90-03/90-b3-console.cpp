/*2152402 ��� ������*/
#include<iostream>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

bool show_graph(char* s, int row, char* name) //��ʾ��row�е�ͼ��
{
    int len = strlen(s);
    for (int col = 0;col < len;++col) {
        char type = s[col];
        int x = col * 6, y = (row - 1) * 3;
        if (type == '9')
            for (int i = 0;i < 3;++i)
                cct_showstr(x, y + i, "      ", 0, 0);
        else if (type == 'W' || type == 'w') {
            cct_showstr(x, y, "�X�T�[", 4, 0);
            cct_showstr(x, y + 1, "�UXX�U", 4, 0);
            cct_showstr(x, y + 2, "�^�T�a", 4, 0);
        }
        else if (type == '0')
            for (int i = 0;i < 3;++i)
                cct_showstr(x, y + i, "      ", 7, 7);
        else if (type == 'B' || type == 'b') {
            cct_showstr(x, y, "�X�T�[", 2, 14);
            cct_showstr(x, y + 1, "�U��U", 2, 14);
            cct_showstr(x, y + 2, "�^�T�a", 2, 14);
        }
        else if (type == 'F' || type == 'f') {
            cct_showstr(x, y, "�X�T�[", 11, 10);
            cct_showstr(x, y + 1, "�U��U", 11, 10);
            cct_showstr(x, y + 2, "�^�T�a", 11, 10);
        }
        else if (type == 'S' || type == 's') {
            cct_showstr(x, y, "�X�T�[", 9, 7);
            cct_showstr(x, y + 1, "�U��U", 9, 7);
            cct_showstr(x, y + 2, "�^�T�a", 9, 7);
        }
        else if (type == 'R' || type == 'r') {
            cct_showstr(x, y, "�X�T�[", 14, 4);
            cct_showstr(x, y + 1, "�U��U", 14, 4);
            cct_showstr(x, y + 2, "�^�T�a", 14, 4);
        }
        else {
            cct_setcolor();
            cct_gotoxy(0, 45);
            cout << "�����������ļ�[" << "[Sokoban-Level-" << name << ".txt]" << "]�зǷ��ַ���" << row << "��" << col + 1 << "�У������س�������" << endl;
            wait_for_enter();
            return 0;
        }
    }
    return 1;
}