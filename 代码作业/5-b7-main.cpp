/*2152402 ��� ������*/
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
    cout << "�� " << src << " �ƶ��� " << dst << "��" << "�� " << n << " �㣬";
    cout << "��ʱ����Ϊ " << delay_time << "��";
    if (!show_array)
        cout << "��";
    cout << "��ʾ�ڲ�����ֵ" << endl;
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
            cout << "��ʼ:               ";
        else
            cout << "��" << setw(4) << steps << "��(" << x << "#: " << src << "-->" << dst << ")";
        print_all();
    }
    if (steps || show_array)
        go_to_next_step();
    if (steps && !show_array)
    {
        cct_gotoxy(0, 17);
        cct_gotoxy(0, 17);
        cout << "��" << setw(4) << steps << "��(" << x << "#: " << src << "-->" << dst << ")";
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
  �������ƣ�hanoi
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ����
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
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
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (n >= 1 && n <= 10)
            break;
    }
    char src, dst, tmp;
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if (dst > 'Z')
            dst -= 32;
        if (dst == src)
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
        if (dst >= 'A' && dst <= 'C' && dst != src)
            break;
    }
    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
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
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}