/*2152402 软件 段婷婷*/
#include<iostream>
#include<windows.h>
#include<iomanip>
#include <conio.h>
#include"5-b7.h"
using namespace std;

int steps = 0;
int top0, top1, top2;
int stack0[10], stack1[10], stack2[10];
int delay_time, show_array;

void go_to_next_step() 
{
    if(delay_time==0)
    {
        while (1)
        {
            int op2 = _getch();
            if (op2 == 13)
                break;
        }
    }
    else
        Sleep((6 - delay_time) * 200);
}
void show_first_line(char src, char dst, int n)
{
    cout << "从 " << src << " 移动到 " << dst << "，" << "共 " << n << " 层，";
    cout << "延时设置为 " << delay_time << "，";
    if (!show_array)
        cout << "不";
    cout << "显示内部数组值" << endl;
}
void print(int ind)
{
    cout << setw(2) << char(ind + 'A') << ":";
    if (ind == 0)
    {
        for (int i = 0;i < top0;++i)
            cout << setw(2) << stack0[i];
        for (int i = 1;i <= 10 - top0;++i)
            cout << " ";
    }
    else if (ind == 1)
    {
        for (int i = 0;i < top1;++i)
            cout << setw(2) << stack1[i];
        for (int i = 1;i <= 10 - top1;++i)
            cout << " ";
    }
    else
    {
        for (int i = 0;i < top2;++i)
            cout << setw(2) << stack2[i];
        for (int i = 1;i <= 10 - top2;++i)
            cout << " ";
    }
}
void print_all()
{
    print(0);
    print(1);
    print(2);
    cout << endl;
}

void draw_hanoi()
{
    cct_gotoxy(9, 12);
    cout << "=========================";
    cct_gotoxy(11, 13);
    cout << 'A';
    int x = 10, y = 12;
    for (int i = 0;i < top0;++i)
    {
        cct_gotoxy(x, --y);
        cout << setw(2) << stack0[i] << " ";
    }
    for (int i = 1;i <= top1 + top2;++i)
    {
        cct_gotoxy(x, --y);
        cout << "  ";
    }
    cct_gotoxy(21, 13);
    cout << 'B';
    x = 20, y = 12;
    for (int i = 0;i < top1;++i)
    {
        cct_gotoxy(x, --y);
        cout << setw(2) << stack1[i] << " ";
    }
    for (int i = 1;i <= top0 + top2;++i)
    {
        cct_gotoxy(x, --y);
        cout << "  ";
    }
    cct_gotoxy(31, 13);
    cout << 'C';
    x = 30, y = 12;
    for (int i = 0;i < top2;++i)
    {
        cct_gotoxy(x, --y);
        cout << setw(2) << stack2[i] << " ";
    }
    for (int i = 1;i <= top0 + top1;++i)
    {
        cct_gotoxy(x, --y);
        cout << "  ";
    }
}

void draw_all(char src, char dst, int x)
{
    if (steps != 0 && show_array)
        go_to_next_step();
    if (show_array)
    {
        cct_gotoxy(0, 17);
        if (steps == 0)
            cout << "初始:               ";
        else
            cout << "第" << setw(4) << steps << "步(" << x << "#: " << src << "-->" << dst << ")";
        print_all();
    }
    if (steps || show_array)
        go_to_next_step();
    if (steps && !show_array)
    {
        cct_gotoxy(0, 17);
        cct_gotoxy(0, 17);
        cout << "第" << setw(4) << steps << "步(" << x << "#: " << src << "-->" << dst << ")";
    }
    draw_hanoi();
    ++steps;
}

int pop(int ind)
{
    if (ind == 0)
        return stack0[--top0];
    if (ind == 1)
        return stack1[--top1];
    return stack2[--top2];
}

void push(int ind, int x)
{
    if (ind == 0)
        stack0[top0++] = x;
    else if (ind == 1)
        stack1[top1++] = x;
    else
        stack2[top2++] = x;
}
/***************************************************************************
  函数名称：hanoi
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：无
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int f_ind = src - 'A', t_ind = dst - 'A', x;
    if (n == 1)
    {
        x = pop(f_ind);
        push(t_ind, x);
        draw_all(src, dst, x);
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    x = pop(f_ind);
    push(t_ind, x);
    draw_all(src, dst, x);
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (n >= 1 && n <= 10)
            break;
    }
    char src, dst, tmp;
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
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show_array;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (show_array == 0 || show_array == 1)
            break;
    }
    tmp = 'A' + 'C' + 'B' - src - dst;
    for (int i = n;i >= 1;--i)
    {
        int ind = src - 'A';
        push(ind, i);
    }

    cct_cls();
    show_first_line(src, dst, n);
    draw_all(src, dst, 0);

    hanoi(n, src, tmp, dst);

    go_to_next_step();
    cct_gotoxy(0, 27);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}