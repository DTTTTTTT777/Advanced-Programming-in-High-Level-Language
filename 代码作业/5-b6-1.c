/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int steps = 0;
int top0, top1, top2;
int stack0[10], stack1[10], stack2[10];

void print(int ind)
{
    printf("%2c:", ind + 'A');
    if (ind == 0)
    {
        for (int i = 0;i < top0;++i)
            printf("%2d", stack0[i]);
        for (int i = 1;i <= 10 - top0;++i)
            printf("  ");
    }
    else if (ind == 1)
    {
        for (int i = 0;i < top1;++i)
            printf("%2d", stack1[i]);
        for (int i = 1;i <= 10 - top1;++i)
            printf("  ");
    }
    else
    {
        for (int i = 0;i < top2;++i)
            printf("%2d", stack2[i]);
        for (int i = 1;i <= 10 - top2;++i)
            printf("  ");
    }
}
void print_all() 
{
    print(0);
    print(1);
    print(2);
    printf("\n");
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
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int f_ind = src - 'A', t_ind = dst - 'A', x;
    if (n == 1)
    {
        x = pop(f_ind);
        printf("��%4d ��(%2d): ", ++steps, x);
        printf("%c-->%c", src, dst);
        push(t_ind, x);
        print_all();
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    x = pop(f_ind);
    printf("��%4d ��(%2d): ", ++steps, x);
    printf("%c-->%c", src, dst);
    push(t_ind, x);
    print_all();
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    int n;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        scanf("%d", &n);
        rewind(stdin);
        if (n >= 1 && n <= 10)
            break;
    }
    char src, dst, tmp;
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
        scanf("%c", &src);
        while (src == ' ' || src == '\n')
            scanf("%c", &src);
        rewind(stdin);
        if (src > 'Z')
            src -= 32;
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1)
    {
        printf("������Ŀ����(A-C)\n");
        scanf("%c", &dst);
        while (dst == ' ' || dst == '\n')
            scanf("%c", &dst);
        rewind(stdin);
        if (dst > 'Z')
            dst -= 32;
        if (dst == src)
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
        if (dst >= 'A' && dst <= 'C' && dst != src)
            break;
    }
    tmp = 'A' + 'C' + 'B' - src - dst;
    for (int i = n;i >= 1;--i)
    {
        int ind = src - 'A';
        push(ind, i);
    }
    printf("��ʼ:               ");
    print_all();
    hanoi(n, src, tmp, dst);
    return 0;
}
/*
* ��˼����Ϊʲô top ��ָ��ջ��������ջ��+1����ʲô�ô���
* �����ж�ջ����ջ����
* topָ��ջ��+1����top=0ʱ��ջ�գ���top����ջ�Ĵ�Сʱ��ջ����
* ����������£�top��ֵ����ջ��Ԫ�صĸ�����
*/