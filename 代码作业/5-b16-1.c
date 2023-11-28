/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void input(char num[10][8], char name[10][9], int score[10])
{
	for (int i = 0;i < 10;++i)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s%s%d", num[i], name[i], &score[i]);
	}
}

void sort_by_num(char num[10][8], char name[10][9], int score[10])
{
	for (int k = 1;k < 10;++k)
		for (int i = 0;i < 10 - k;++i)
			if (strcmp(num[i], num[i + 1]) < 0)
			{
				char stmp[9];
				int itmp;

				strcpy(stmp, num[i]);
				strcpy(num[i], num[i + 1]);
				strcpy(num[i + 1], stmp);

				strcpy(stmp, name[i]);
				strcpy(name[i], name[i + 1]);
				strcpy(name[i + 1], stmp);

				itmp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = itmp;
			}

}
void print(char num[10][8], char name[10][9], int score[10])
{
	printf("\n及格名单(学号降序):\n");
	for (int i = 0;i < 10;++i)
		if (score[i] >= 60)
		{
			printf("%s %s %d\n", name[i], num[i], score[i]);
		}
}
int main()
{
	char num[10][8], name[10][9];
	int score[10];

	input(num, name, score);
	sort_by_num(num, name, score);
	print(num, name, score);

	return 0;
}
/*
*   为什么学号用字符串而非整型？
	因为学号可能含有前导0，整型无法存储。
*/

/*
1850772 张哲源 77
1953756 刘一 52
2052306 王伟杰 83
2150863 刘锐 38
2151713 汪心成 49
2151974 赵明泽 73
2152472 司盛宇 92
2152847 周佳蕾 63
2153269 邢伟东 38
2153877 唐书涵 63

1850772 张哲源 77
1953756 刘一 52
2052306 王伟杰 83
2150863 刘锐 38
2151713 汪心成 49
2151974 赵明泽 73
2151974 司盛宇 60
2152847 周佳蕾 59
2153269 邢伟东 38
2153877 唐书涵筱 60
*/