/*2152402 ��� ������*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>
#include<iomanip>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����
	bool in[2];             // in[0/1] : ��1/2���Ƿ�ѡ��
	friend stu_list;
	stu_info();
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	int n;  //ѧ����Ŀ
	/* ���������private���ݳ�Ա�ͳ�Ա���� */

public:
	stu_list();
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			//��ӡ��ǰ�����ѡ������
	void sort_stu();
	/* �������������public��Ա���� */
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
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
		cout << "�ļ�[" << filename << "]��ʧ��" << endl;
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
	for (int k = 1;k < n;++k)					//ѭ�� n - 1 ��
		for (int i = 0;i < n - k;++i)			//��k��ѭ�������� k ���Ԫ��ð���������е� n - k  ��λ����
			if (stu[i].stu_no > stu[i + 1].stu_no)             //�ҵ����򣬽���
				swap(stu[i], stu[i + 1]);
}
int stu_list::print(const char* prompt)
{
	if (prompt != NULL)
		cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
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
			cout << "�˿�";
		else
			cout << "��ѡ";
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 1;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}