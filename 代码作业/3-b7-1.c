/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double rmb;
	int tmp;
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	printf("请输入找零值：\n");
	scanf("%lf", &rmb);
	rmb += 0.001;

	tmp = (int)(rmb);

	t1 = tmp / 50;
	tmp -= t1 * 50;

	t2 = tmp / 20;
	tmp -= t2 * 20;

	t3 = tmp / 10;
	tmp -= t3 * 10;

	t4 = tmp / 5;
	tmp -= t4 * 5;

	t5 = tmp;

	tmp = rmb * 100 - (int)(rmb) * 100;

	t6 = tmp / 50;
	tmp -= t6 * 50;

	t7 = tmp / 10;
	tmp -= t7 * 10;

	t8 = tmp / 5;
	tmp -= t8 * 5;

	t9 = tmp / 2;
	tmp -= t9 * 2;

	t10 = tmp;

	printf("共%d张找零，具体如下：\n", t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10);
	if (t1 != 0)
		printf("50元 : %d张\n",t1);
	if (t2 != 0)
		printf("20元 : %d张\n", t2);
	if (t3 != 0)
		printf("10元 : %d张\n", t3);
	if (t4 != 0)
		printf("5元  : %d张\n", t4);
	if (t5 != 0)
		printf("1元  : %d张\n", t5);
	if (t6 != 0)
		printf("5角  : %d张\n", t6);
	if (t7 != 0)
		printf("1角  : %d张\n", t7);
	if (t8 != 0)
		printf("5分  : %d张\n", t8);
	if (t9 != 0)
		printf("2分  : %d张\n", t9);
	if (t10 != 0)
		printf("1分  : %d张\n", t10);

	return 0;
}