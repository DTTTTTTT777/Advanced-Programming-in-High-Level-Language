/*2152402 ��� ������*/
#include<iostream>
#include<string>
using namespace std;

void input(string num[10], string name[10], int score[10])
{
	for (int i = 0;i < 10;++i)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
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
	cout << endl << "ȫ��ѧ��(ѧ������):" << endl;
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

0050772 ����Դ 77
1953756 ��һ 77
2052306 ��ΰ�� 38
2150863 ���� 38
2151713 ���ĳ� 59
2151974 ������ 60
2151974 ˾ʢ�� 59
2152847 �ܼ��� 99
2153269 ��ΰ�� 38
2151974 ���麭�� 59
*/