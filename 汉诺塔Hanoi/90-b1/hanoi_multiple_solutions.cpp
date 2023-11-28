/*2152402 软件 段婷婷*/
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<windows.h>
using namespace std;

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
static int steps = 0;
static int top[3], stack[3][10];
static int delay_time;

void sol_for_123(int opt)
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 0);

    hanoi(n, src, tmp, dst, opt);

    Pause(-1);
}

void sol_for_opt4()
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 1);

    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，" << "共 " << n << " 层，";
    cout << "延时设置为 " << delay_time << "，";
    show_arrays(src, dst, 0, 17);

    hanoi(n, src, tmp, dst, 4);

    Pause(27);
}
void draw_for_opt5()
{
    cct_cls();
    draw_cylinder();

    Pause(27);
}
void draw_for_opt6()
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 0);
    init_graph(n, src, dst, 0);

    Pause(27);
}

void draw_for_opt7()
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 0);
    init_graph(n, src, dst, 0);

    char to = n % 2 == 1 ? dst : tmp;
    stack[to - 'A'][top[to - 'A']++] = stack[src - 'A'][--top[src - 'A']];
    draw_move(1, src, to);

    Pause(27);
}
void draw_for_opt8()
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 1);
    init_graph(n, src, dst, 1);

    show_arrays(src, dst, 0, 32);
    hanoi(n, src, tmp, dst, 8);

    Pause(37);
}
void draw_for_opt9()
{
    int n;
    char src, dst, tmp;
    init_input(n, src, dst, tmp, 0);
    delay_time = 2;

    init_graph(n, src, dst, 0);
    show_arrays(src, dst, 0, 32);

    while (1)
    {
        cct_gotoxy(0, 34);
        cct_setcursor(2);
        cct_setcolor();
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：       ";
        cct_gotoxy(0, 34);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

        char fr = _getche(), to = _getche();
        if (fr == 'q' || fr == 'Q')
        {
            cct_gotoxy(0, 35);
            cout << "游戏中止!!!!!";
            break;
        }
        if (fr > 'C')
            fr -= 32;
        if (to > 'C')
            to -= 32;
        if (fr < 'A' || fr>'C' || to < 'A' || to>'C' || fr == to)
            continue;
        if (top[fr - 'A'] == 0)
        {
            cct_gotoxy(0, 35);
            cout << "柱源为空！";
            Sleep(100);
            cct_gotoxy(0, 35);
            cout << "                                     ";
            continue;
        }
        if (top[to - 'A'] && stack[to - 'A'][top[to - 'A'] - 1] < stack[fr - 'A'][top[fr - 'A'] - 1])
        {
            cct_gotoxy(0, 35);
            cout << "非法移动，大盘压小盘！";
            Sleep(100);
            cct_gotoxy(0, 35);
            cout << "                                     ";
            continue;
        }

        int x = stack[fr - 'A'][--top[fr - 'A']];
        stack[to - 'A'][top[to - 'A']++] = x;

        show_arrays(fr, to, x, 32);
        draw_move(x, fr, to);

        if (top[dst - 'A'] == n)
        {
            cct_gotoxy(0, 35);
            cct_setcolor();
            cout << "游戏中止!!!!!";
            break;
        }
    }

    Pause(38);
}

void init_input(int& n, char& src, char& dst, char& tmp, bool delay)
{
    steps = 0;
    top[0] = top[1] = top[2] = 0;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        if (n >= 1 && n <= 16)
            break;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (src > 'Z')
            src -= 32;
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (dst > 'Z')
            dst -= 32;
        if (dst == src)
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
        if (dst >= 'A' && dst <= 'C' && dst != src)
            break;
    }
    tmp = 'A' + 'C' + 'B' - src - dst;
    for (int i = n;i >= 1;--i)
    {
        int ind = src - 'A';
        stack[ind][top[ind]++] = i;
    }
    if (delay)
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> delay_time;
            if (!cin.good())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            if (delay_time >= 0 && delay_time <= 5)
                break;
        }
    }
    else
        delay = 0;
}
void Pause(int y)
{
    if (y != -1)
        cct_gotoxy(0, y);
    cct_setcolor();
    cout << endl << "按回车键继续";
    int X = 0, Y = 0, ret, maction, keycode1, keycode2;
    while (1)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT && keycode1 == 13)
            break;
    }
}

void go_to_next_step(bool enter)
{
    double delay_time_arr[5] = { 100,50,1,1e-3,1e-6 };
    if (delay_time == 0 && enter)
    {
        while (1)
        {
            int op2 = _getch();
            if (op2 == 13)
                break;
        }
    }
    else
        Sleep(delay_time_arr[delay_time]);
}
void show_array_transverse()
{
    for (int ind = 0;ind < 3;++ind)
    {
        cout << setw(2) << char(ind + 'A') << ":";
        for (int i = 0;i < top[ind];++i)
            cout << setw(2) << stack[ind][i];
        for (int i = 1;i <= 10 - top[ind];++i)
            cout << "  ";
    }
    cout << endl;
}
void show_array_portrait(int Y)
{
    cct_setcolor();
    cct_gotoxy(9, Y);
    cout << "=========================";
    for (int ind = 0;ind < 3;++ind)
    {
        cct_gotoxy(11 + 10 * ind, Y + 1);
        cout << char('A' + ind);
        int x = 10 + 10 * ind, y = Y;
        for (int i = 0;i < top[ind];++i)
        {
            cct_gotoxy(x, --y);
            cout << setw(2) << stack[ind][i] << " ";
        }
        int rest = top[0] + top[1] + top[2] - top[ind];
        for (int i = 1;i <= rest;++i)
        {
            cct_gotoxy(x, --y);
            cout << "  ";
        }
    }
}
void show_arrays(char src, char dst, int x, int y)  //画纵向和横向数组
{
    cct_setcolor();
    if (steps != 0)
        go_to_next_step(1);
    cct_gotoxy(0, y);
    if (steps == 0)
        cout << "初始:              ";
    else
        cout << "第" << setw(4) << steps << "步(" << x << "#: " << src << "-->" << dst << ")";
    show_array_transverse();
    show_array_portrait(y - 5);
    ++steps;
}

void draw_cylinder()
{
    cct_setcursor(CURSOR_INVISIBLE);
    cct_showch(1, 15, ' ', 14, 0, 23);
    cct_showch(34, 15, ' ', 14, 0, 23);
    cct_showch(67, 15, ' ', 14, 0, 23);

    for (int j = 0;j < 12;++j)
    {
        for (int i = 0;i < 3;++i)
        {
            int x = 12 + i * 33, y = 14;
            cct_showch(x, y - j, ' ', 14, 0, 1);
            Sleep(100);
        }
    }
}
void draw_src_plates(char src, int n)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int x = 12 + 33 * (src - 'A'), y = 14;
    int last_color = -1;
    for (int i = n;i >= 1;--i)
    {
        int bg_color = i;
        cct_showch(x - i, y, ' ', bg_color, 0, i * 2 + 1);
        Sleep(50);
        --y;
    }
}
void init_graph(int n, char src, char dst, bool show_delay)
{
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
    if (show_delay)
        cout << "延时设置为 " << delay_time;
    draw_cylinder();
    draw_src_plates(src, n);
}

void draw_move(int n, char src, char dst)
{
    int sy = 14 - top[src - 'A'], ty = 15 - top[dst - 'A'];
    int sx = 12 + 33 * (src - 'A'), tx = 12 + 33 * (dst - 'A');
    int bg_color = n;

    for (int y = sy;y >= 1;--y)
    {
        cct_showch(sx - n, y, ' ', bg_color, 0, n * 2 + 1);
        go_to_next_step(0);
        cct_showch(sx - n, y, ' ', 0, 0, n * 2 + 1);
        if (y > 2)
            cct_showch(sx, y, ' ', 14, 0, 1);
    }

    if (sx < tx)
        for (int x = sx;x <= tx;++x)
        {
            cct_showch(x - n, 1, ' ', bg_color, 0, n * 2 + 1);
            go_to_next_step(0);
            cct_showch(x - n, 1, ' ', 0, 0, n * 2 + 1);
        }
    else
        for (int x = sx;x >= tx;--x)
        {
            cct_showch(x - n, 1, ' ', bg_color, 0, n * 2 + 1);
            go_to_next_step(0);
            cct_showch(x - n, 1, ' ', 0, 0, n * 2 + 1);
        }

    for (int y = 1;y <= ty;++y)
    {
        cct_showch(tx - n, y, ' ', bg_color, 0, n * 2 + 1);
        go_to_next_step(0);
        if (y == ty)
            break;
        cct_showch(tx - n, y, ' ', 0, 0, n * 2 + 1);
        if (y > 2)
            cct_showch(tx, y, ' ', 14, 0, 1);
    }
}

void hanoi_output_move(int n, char src, char dst, int opt)
{
    int f_ind = src - 'A', t_ind = dst - 'A';
    if (opt == 1)
        cout << n << "# " << src << "---->" << dst << endl;
    else if (opt == 2)
        cout << "第" << setw(4) << ++steps << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    else if (opt == 3)
        cout << "第" << setw(4) << ++steps << " 步(" << setw(2) << stack[f_ind][top[f_ind] - 1] << "#: " << src << "-->" << dst << ") ";

    int x = stack[f_ind][top[f_ind] - 1];
    stack[t_ind][top[t_ind]++] = stack[f_ind][--top[f_ind]];

    if (opt == 3)
        show_array_transverse();
    else if (opt == 4)
        show_arrays(src, dst, x, 17);
    else if (opt == 8)
    {
        show_arrays(src, dst, x, 32);
        draw_move(n, src, dst);
    }
}

void hanoi(int n, char src, char tmp, char dst, int opt)
{
    if (n == 1)
    {
        hanoi_output_move(n, src, dst, opt);
        return;
    }
    hanoi(n - 1, src, dst, tmp, opt);
    hanoi_output_move(n, src, dst, opt);
    hanoi(n - 1, tmp, src, dst, opt);
}
