/*2152402 软件 段婷婷*/
#include<iostream>
#include<string>
using namespace std;

void input(string num[10], string name[10], int score[10])
{
	for (int i = 0;i < 10;++i)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[i] >> name[i] >> score[i];
	}
}

void sort_by_num(string num[10], string name[10], int score[10])
{
	for (int k = 1;k < 10;++k)
		for (int i = 0;i < 10 - k;++i)
			if (num[i] > num[i + 1])
			{
				string stmp;
				int itmp;

				stmp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = stmp;

				stmp = name[i];
				name[i] = name[i + 1];
				name[i + 1] = stmp;

				itmp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = itmp;
			}

}
void print(string num[10], string name[10], int score[10])
{
	cout << endl << "全部学生(学号升序):" << endl;
	for (int i = 0;i < 10;++i)
			cout << name[i] << " " << num[i] << " " << score[i] << endl;
}
int main()
{
	string num[10], name[10];
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

0050772 张哲源 77
1953756 刘一 77
2052306 王伟杰 38
2150863 刘锐 38
2151713 汪心成 59
2151974 赵明泽 60
2151974 司盛宇 59
2152847 周佳蕾 99
2153269 邢伟东 38
2151974 唐书涵筱 59
*/