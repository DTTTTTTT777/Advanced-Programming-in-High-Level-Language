/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int a[1001], num = 0, count[101];
	printf("请输入成绩（最多1000个），以-1结束\n");
	for (int i = 1;i <= 1000;++i)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
			break;
		++num;
	}
	if (!num)
	{
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:\n");
	for (int i = 1;i <= num;++i)
	{
		printf("%d ", a[i]);
		if (i % 10 == 0)
			printf("\n");
	}
	if (num % 10)
		printf("\n");

	for (int i = 0;i <= 100;++i)
		count[i] = 0;
	for (int i = 1;i <= num;++i)
		++count[a[i]];

	printf("分数与人数的对应关系为:\n");
	for (int i = 100;i >= 0;--i)
		if (count[i])
			printf("%d %d\n", i, count[i]);

	return 0;
}