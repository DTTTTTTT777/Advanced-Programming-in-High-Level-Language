/*2152402 软件 段婷婷*/
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
string result;

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
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "拾";
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
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag1)
		result += "亿";

	//千万、百万、十万、万--------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//千万：
	tmp = int(rmb / 100000000);
	val = int(rmb - tmp * 100000000.0) / 10000000;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "仟";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;

		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "佰";

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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "拾";

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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag3)
		result += "万";

	//千、百、十、元------------------------------------------------------------------------------------
	flag2 = 0;
	flag3 = 0;
	//千：
	tmp = int(rmb / 10000);
	val = int(rmb - tmp * 10000.0) / 1000;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "仟";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "佰";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (val != 0)
		result += "拾";
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
			result.push_back(chnstr[0]);
			result.push_back(chnstr[1]);
			flag2 = 0;
		}
		flag1 = 1;
		if (val >= 1 && val <= 9)
		{
			result.push_back(chnstr[val << 1]);
			result.push_back(chnstr[(val << 1) + 1]);
		}
	}
	if (flag1)
		result += "圆";

	//角、分--------------------------------------------------------------------------------------------------------------
	flag3 = 0; //角/分有无值  (轮着用
	//角：
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "角";
		flag1 = 1;
		flag3 = 1;
	}
	//分：
	trmb -= int(trmb);
	trmb *= 10;
	val = int(trmb);
	if (val != 0 && !flag3 && flag1)
	{
		result.push_back(chnstr[0]);
		result.push_back(chnstr[1]);
	}
	flag3 = 0;
	if (val >= 1 && val <= 9)
	{
		result.push_back(chnstr[val << 1]);
		result.push_back(chnstr[(val << 1) + 1]);
	}
	if (val != 0)
	{
		result += "分";
		flag1 = 1;
		flag3 = 1;
	}
	if (!flag1)
	{
		result.push_back(chnstr[0]);
		result.push_back(chnstr[1]);
		result += "圆整";
	}
	else if (!flag3)
		result += "整";
	cout << result << endl;
	return 0;
}