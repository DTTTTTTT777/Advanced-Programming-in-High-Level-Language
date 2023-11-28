/*2152402 软件 段婷婷*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>
#include<iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list;
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	bool in[2];             // in[0/1] : 第1/2轮是否选课
	friend stu_list;
	stu_info();
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int n;  //学生数目
	/* 允许按需加入private数据成员和成员函数 */

public:
	stu_list();
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单
	void sort_stu();
	/* 允许按需加入其它public成员函数 */
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
stu_info::stu_info()
{
	stu_no = 0;
	in[0] = in[1] = 0;
	strcpy(stu_name, "");
}
stu_list::stu_list()
{
	n = 0;
}
int stu_list::read(const char* filename, const int append)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "文件[" << filename << "]打开失败" << endl;
		return -1;
	}
	if (append == 0) {
		n = 0;
		for (int i = 0;i < MAX_STU_NUM;++i)
			stu[i].in[0] = stu[i].in[1] = 0;
		while (fin >> stu[n].stu_no >> stu[n].stu_name) {
			stu[n].in[0] = 1;
			n++;
		}
		this->sort_stu();
	}
	else {
		int stu_no = 0;
		char stu_name[MAX_NAME_LEN] = "";
		while (fin >> stu_no >> stu_name) {
			bool tag = 0;
			for (int i = 0;i < n;++i)
				if (stu[i].stu_no == stu_no && strcmp(stu[i].stu_name, stu_name) == 0) {
					stu[i].in[1] = 1;
					tag = 1;
					break;
				}
			if (!tag) {
				stu[n].stu_no = stu_no;
				strcpy(stu[n].stu_name, stu_name);
				stu[n].in[0] = 0;
				stu[n].in[1] = 1;
				n++;
			}
		}
		this->sort_stu();
	}
	return 0;
}
void stu_list::sort_stu()
{
	for (int k = 1;k < n;++k)					//循环 n - 1 次
		for (int i = 0;i < n - k;++i)			//第k次循环，将第 k 大的元素冒泡移至序列第 n - k  的位置上
			if (stu[i].stu_no > stu[i + 1].stu_no)             //找到逆序，交换
				swap(stu[i], stu[i + 1]);
}
int stu_list::print(const char* prompt)
{
	if (prompt != NULL)
		cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;
	for (int i = 0;i < n;++i) {
		cout << setiosflags(ios::left) << setw(5) << i + 1;
		cout << setw(8) << stu[i].stu_no;
		cout << setw(33) << stu[i].stu_name;
		if (stu[i].in[0])
			cout << "Y";
		else
			cout << "/";
		cout << "      ";
		if (stu[i].in[0] && stu[i].in[1])
			cout << "Y";
		else if (stu[i].in[0] && !stu[i].in[1])
			cout << "退课";
		else
			cout << "补选";
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}