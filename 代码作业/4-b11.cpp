/*2152402 软件 段婷婷*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */
  
   /***************************************************************************
	函数名称：print_line
	功    能：打印分割的双横线
	输入参数：int n 表示需要打印长度为 2n+1 的双横线
	返 回 值：返回双横线的组成元素'='
  ***************************************************************************/
char print_line(int n)
{
	if (n)
	{
		cout << "==";
		print_line(n - 1);
	}
	return '=';
}

   /***************************************************************************
	 函数名称：print_blank
	 功    能：打印空格
	 输入参数：int n 表示需要打印长度为 n 的空格
	 返 回 值：无
   ***************************************************************************/
void print_blank(int n)
{
	if (!n)
		return;
	cout << ' ';
	print_blank(n - 1);
}
   /***************************************************************************
	 函数名称：print_linech
	 功    能：打印单行字母
	 输入参数：int n 表示当前打印长度为 2n+1 的字母行
			int N 总共打印的字母行长度为 2N+1
			bool op 正序/倒序打印字母行
	 返 回 值：无
   ***************************************************************************/
void print_linech(int n, int N, bool op)
{
	if (op)
	{
		if (n == 0)
		{
			cout << 'A';
			return;
		}
		cout << char('A' + n);
		print_linech(n - 1, N, op);
		cout << char('A' + n);
	}
	else
	{
		if (n == 0)
		{
			cout << char('A' + N - n);
			return;
		}
		cout << char('A' + N - n);
		print_linech(n - 1, N, op);
		cout << char('A' + N - n);
	}
}
   /***************************************************************************
	 函数名称：print_tower
	 功    能：打印字母塔
	 输入参数：int n 当前打印结束字符为 'A'+n 的字母塔
			int N 总的字母塔的结束字符为 'A'+N
			bool op 正序/倒序打印
	 返 回 值：无
	 说    明：形参按需设置
   ***************************************************************************/
void print_tower(int n, int N, bool op)
{
	//cout << n << endl;
	if (n < 0)
		return;
	if (op)
	{
		print_tower(n - 1, N, op);
		print_blank(N - n);
		print_linech(n, N, op);
		cout << endl;
	}
	else
	{
		print_blank(N - n);
		print_linech(n, N, op);
		cout << endl;
		print_tower(n - 1, N, op);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}
	/*cout << end_ch - 'A' << endl;
	return 0;*/

	/* 正三角字母塔(中间为A) */
	cout << print_line(end_ch - 'A') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */

	cout << "正三角字母塔" << endl;
	cout << print_line(end_ch - 'A') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch - 'A', end_ch - 'A', 1);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << print_line(end_ch - 'A') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << print_line(end_ch - 'A') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch - 'A', end_ch - 'A', 0);
	cout << endl;

	return 0;
}