/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

void show_popmenu(char(*file)[4], int n, int beg, int cur) //显示弹出式菜单
{
    cct_cls();
    int x = 100, y = 2;
    cct_gotoxy(x, y);
    cout << " 请选择关卡";
    cct_gotoxy(x, ++y);
    cout << "╔════╗";
    for (int i = beg;i < beg + min(25, n - beg);++i) {
        cct_gotoxy(x, ++y);
        cout << "║关卡" << file[i] << " ║";
    }
    cct_gotoxy(x, ++y);
    cout << "╚════╝";

    y = 3 + cur - beg + 1;
    char s[10] = "关卡";
    strcat(s, file[cur]);
    cct_showstr(x + 2, y, s, 7, 0);
    cct_setcolor();
}

void choose_levels(char(*file)[4], int n) //选择关卡（光标上下移动并更新弹出式菜单）
{
    int beg = 0, cur = 0;
    int X1 = 0, Y1 = 0, ret, maction, keycode1, keycode2;
    while (1) {
        show_popmenu(file, n, beg, cur);
        ret = cct_read_keyboard_and_mouse(X1, Y1, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            if (keycode1 == 224) {
                if (keycode2 == KB_ARROW_UP && cur > 0) {
                    --cur;
                    if (cur < beg)
                        beg = cur;
                }
                else if (keycode2 == KB_ARROW_DOWN && cur < n - 1) {
                    cout << "%%";
                    ++cur;
                    if (cur - beg > 24)
                        beg = cur - 24;
                }
            }
            else if (keycode1 == 13)
                read_file(file[cur]);
            else if (keycode1 == 27) {
                wait_for_end();
                break;
            }
        }
    }
}