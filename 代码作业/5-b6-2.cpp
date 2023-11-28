/*2152402 软件 段婷婷*/
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
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int f_ind = src - 'A', t_ind = dst - 'A';
    if (n == 1)
    {
        cout << "第" << setw(4) << ++steps << " 步(" << setw(2) << stack[f_ind][top[f_ind] - 1] << "): ";
        cout << src << "-->" << dst;
        stack[t_ind][top[t_ind]++] = stack[f_ind][--top[f_ind]];
        print_all();
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << "第" << setw(4) << ++steps << " 步(" << setw(2) << stack[f_ind][top[f_ind] - 1] << "): ";
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
    tmp = 'A' + 'C' + 'B' - src - dst;
    for (int i = n;i >= 1;--i)
    {
        int ind = src - 'A';
        stack[ind][top[ind]++] = i;
    }
    cout << "初始:               ";
    print_all();
    hanoi(n, src, tmp, dst);
    return 0;
}
/*
* 请思考：为什么 top 不指向栈顶，而是栈顶+1，有什么好处？
* 方便判断栈空与栈满：
* top指向栈顶+1，则当top=0时，栈空；当top等于栈的大小时，栈满。
* 在这种情况下，top的值等于栈中元素的个数。
*/