/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void input(char num[10][8], char name[10][9], int score[10])
{
	for (int i = 0;i < 10;++i)
	{
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
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
	printf("\n��������(ѧ�Ž���):\n");
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
*   Ϊʲôѧ�����ַ����������ͣ�
	��Ϊѧ�ſ��ܺ���ǰ��0�������޷��洢��
*/

/*
1850772 ����Դ 77
1953756 ��һ 52
2052306 ��ΰ�� 83
2150863 ���� 38
2151713 ���ĳ� 49
2151974 ������ 73
2152472 ˾ʢ�� 92
2152847 �ܼ��� 63
2153269 ��ΰ�� 38
2153877 ���麭 63

1850772 ����Դ 77
1953756 ��һ 52
2052306 ��ΰ�� 83
2150863 ���� 38
2151713 ���ĳ� 49
2151974 ������ 73
2151974 ˾ʢ�� 60
2152847 �ܼ��� 59
2153269 ��ΰ�� 38
2153877 ���麭�� 60
*/