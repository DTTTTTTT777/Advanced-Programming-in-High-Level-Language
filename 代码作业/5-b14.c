/*2152402 ��� ������*/
/*2151804 ����� 2152871 ���� 2151350 �֥ 2152520 ���ȷ� 2151716 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int min(int x, int y)
{
	return x < y ? x : y;
}
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	char map[10][26];
	for (int i = 0;i < 10;++i)
		for (int j = 0;j < 26;++j)
		{
			scanf("%c", &map[i][j]);
			while (map[i][j] == ' ' || map[i][j] == '\n')
				scanf("%c", &map[i][j]);
		}

	int num = 0;
	for (int i = 0;i < 10;++i)
		for (int j = 0;j < 26;++j)
			if (map[i][j] == '*')
				++num;
	if (num != 50)
	{
		printf("����1\n");
		return 0;
	}

	for (int x = 0;x < 10;++x)
		for (int y = 0;y < 26;++y)
		{
			if (map[x][y] == '*')
				continue;
			int tot = 0;
			for (int i = max(0, x - 1);i <= min(9, x + 1);++i)
				for (int j = max(0, y - 1);j <= min(25, y + 1);++j)
					if (map[i][j] == '*')
						++tot;
			if (map[x][y] - '0' != tot)
			{
				printf("����2\n");
				return 0;
			}
		}

	printf("��ȷ\n");
}