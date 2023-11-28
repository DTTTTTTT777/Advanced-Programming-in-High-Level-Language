/*2152402 软件 段婷婷*/
#include<iostream>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

bool show_graph(char* s, int row, char* name) //显示第row行的图形
{
    int len = strlen(s);
    for (int col = 0;col < len;++col) {
        char type = s[col];
        int x = col * 6, y = (row - 1) * 3;
        if (type == '9')
            for (int i = 0;i < 3;++i)
                cct_showstr(x, y + i, "      ", 0, 0);
        else if (type == 'W' || type == 'w') {
            cct_showstr(x, y, "╔═╗", 4, 0);
            cct_showstr(x, y + 1, "║XX║", 4, 0);
            cct_showstr(x, y + 2, "╚═╝", 4, 0);
        }
        else if (type == '0')
            for (int i = 0;i < 3;++i)
                cct_showstr(x, y + i, "      ", 7, 7);
        else if (type == 'B' || type == 'b') {
            cct_showstr(x, y, "╔═╗", 2, 14);
            cct_showstr(x, y + 1, "║★║", 2, 14);
            cct_showstr(x, y + 2, "╚═╝", 2, 14);
        }
        else if (type == 'F' || type == 'f') {
            cct_showstr(x, y, "╔═╗", 11, 10);
            cct_showstr(x, y + 1, "║●║", 11, 10);
            cct_showstr(x, y + 2, "╚═╝", 11, 10);
        }
        else if (type == 'S' || type == 's') {
            cct_showstr(x, y, "╔═╗", 9, 7);
            cct_showstr(x, y + 1, "║♀║", 9, 7);
            cct_showstr(x, y + 2, "╚═╝", 9, 7);
        }
        else if (type == 'R' || type == 'r') {
            cct_showstr(x, y, "╔═╗", 14, 4);
            cct_showstr(x, y + 1, "║★║", 14, 4);
            cct_showstr(x, y + 2, "╚═╝", 14, 4);
        }
        else {
            cct_setcolor();
            cct_gotoxy(0, 45);
            cout << "推箱子数据文件[" << "[Sokoban-Level-" << name << ".txt]" << "]有非法字符（" << row << "行" << col + 1 << "列），按回车键继续" << endl;
            wait_for_enter();
            return 0;
        }
    }
    return 1;
}