/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double rmb, trmb;
	int tmp, val;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	//flag1：是否已经出现第一个非零数   flag2: 在出现了第一个非零数的情况下，前面是否有还未输出的零 flag3：当前部分是否出现了非零

	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> rmb;
	rmb += 0.001;
	cout << "大写结果是:" << endl;

	//第一部分：十亿、亿-------------------------------------------------------------------------
	//十亿：
	tmp = int(rmb / 1000000000);
	val = tmp;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "拾";
		flag1 = 1;
	}

	//亿：
	val = int(rmb - tmp * 1000000000.0) / 100000000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag1)
		cout << "亿";

	//千万、百万、十万、万--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//千万：
	tmp = int(rmb / 100000000);
	val = int(rmb - tmp * 100000000.0) / 10000000;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "仟";
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//百万：
	tmp = int(rmb / 10000000);
	val = int(rmb - tmp * 10000000.0) / 1000000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;

		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "佰";

	//十万：
	tmp = int(rmb / 1000000);
	val = int(rmb - tmp * 1000000.0) / 100000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "拾";

	//万：
	tmp = int(rmb / 100000);
	val = int(rmb - tmp * 100000.0) / 10000;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag3)
		cout << "万";

	//千、百、十、元------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//千：
	tmp = int(rmb / 10000);
	val = int(rmb - tmp * 10000.0) / 1000;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "仟";
		flag1 = 1;
		flag3 = 1;
	}
	else if (flag1)
		flag2 = 1;

	//百：
	tmp = int(rmb / 1000);
	val = int(rmb - tmp * 1000.0) / 100;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "佰";
	//cout << flag1 << flag2;
	//十：
	tmp = int(rmb / 100);
	val = int(rmb - tmp * 100.0) / 10;
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (val != 0)
		cout << "拾";
	//元：
	trmb = rmb - tmp * 100.0;
	tmp = int(trmb / 10);
	val = int(trmb - tmp * 10.0);
	if (val == 0)
	{
		if (flag1)
			flag2 = 1;
	}
	else
	{
		flag3 = 1;
		if (flag1 && flag2)
		{
			daxie(0,1);
			flag2 = 0;
		}
		flag1 = 1;
		if (val == 1)
			daxie(1,0);
		else if (val == 2)
			daxie(2,0);
		else if (val == 3)
			daxie(3,0);
		else if (val == 4)
			daxie(4,0);
		else if (val == 5)
			daxie(5,0);
		else if (val == 6)
			daxie(6,0);
		else if (val == 7)
			daxie(7,0);
		else if (val == 8)
			daxie(8,0);
		else if (val == 9)
			daxie(9,0);
	}
	if (flag1)
		cout << "圆";

	//角、分--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //角/分有无值  (轮着用
	//角：
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "角";
		flag1 = 1;
		flag3 = 1;
	}
	//分：
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val != 0 && !flag3 && flag1)
		daxie(0,1);
	flag3 = 0;
	if (val == 1)
		daxie(1,0);
	else if (val == 2)
		daxie(2,0);
	else if (val == 3)
		daxie(3,0);
	else if (val == 4)
		daxie(4,0);
	else if (val == 5)
		daxie(5,0);
	else if (val == 6)
		daxie(6,0);
	else if (val == 7)
		daxie(7,0);
	else if (val == 8)
		daxie(8,0);
	else if (val == 9)
		daxie(9,0);
	if (val != 0)
	{
		cout << "分";
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
	{
		daxie(0, 1);
		cout << "圆整";
	}
	else if (!flag3)
		cout << "整";
	cout << endl;
	return 0;
}