/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
using namespace std;

int steps = 0;
int top[3], stack[3][10];

void print(int ind)
{
    cout << setw(2) << char(ind + 'A') << ":";
    for (int i = 0;i < top[ind];++i)
        cout << setw(2) << stack[ind][i];
    for (int i = 1;i <= 10 - top[ind];++i)
        cout << "  ";
}
void print_all()
{
    print(0);
    print(1);
    print(2);
    cout << endl;
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
    int f_ind = src - 'A', t_ind = dst - 'A';
    if (n == 1)
    {
        cout << "��" << setw(4) << ++steps << " ��(" << setw(2) << stack[f_ind][top[f_ind] - 1] << "): ";
        cout << src << "-->" << dst;
        stack[t_ind][top[t_ind]++] = stack[f_ind][--top[f_ind]];
        print_all();
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << "��" << setw(4) << ++steps << " ��(" << setw(2) << stack[f_ind][top[f_ind] - 1] << "): ";
    cout << src << "-->" << dst;
    stack[t_ind][top[t_ind]++] = stack[f_ind][--top[f_ind]];
    print_all();
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
    tmp = 'A' + 'C' + 'B' - src - dst;
    for (int i = n;i >= 1;--i)
    {
        int ind = src - 'A';
        stack[ind][top[ind]++] = i;
    }
    cout << "��ʼ:               ";
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