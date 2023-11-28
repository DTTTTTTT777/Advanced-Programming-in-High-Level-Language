/*2152402 ��� ������*/
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int N = 500;

void input(char* file_name) {
	cerr << "�ļ���������ʽ������:" << endl;
	cerr << "    a.txt                    : ����·����ʽ" << endl;
	cerr << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
	cerr << "�������ļ��� : ";
	cin.getline(file_name, N - 1);
}
void output_char(int idx, int* row, int tag) {
	for (int i = idx + tag ; i < 16;++i)
		cout << "   ";
	if (!tag && idx <= 8)
		cout << "  ";
	cout << "  ";
	for (int i = 0;i < idx + tag;++i)
		if (row[i] >= 33 && row[i] <= 126)
			cout << char(row[i]);
		else
			cout << ".";
	cout << endl;
}
void output_hex(int ch) {
	cout << " " << setfill('0') << setw(2) << hex << ch;
}
int main()
{
	char file_name[N];
	input(file_name);
	ifstream in_file(file_name, ios::in | ios::binary);
	if (!in_file.is_open()) {
		cout << "�����ļ�" << file_name << "��ʧ��!" << endl;
		return 0;
	}

	int idx = -1, row[20];
	cout << setiosflags(ios::uppercase); //ʮ���������ʱ��д
	while (1) {
		int ch = in_file.get(); //��һ���ֽ�
		idx = (idx + 1) % 16;  //�±�++
		row[idx] = ch;           //�浽����row

		if (ch == EOF) {
			if (idx > 0)
				output_char(idx, row, 0);  //�������16����һ�����
			break;
		}

		if (idx == 0)   //���8λ��λ��
			cout << setfill('0') << setw(8) << hex << int(in_file.tellg()) - 1 << ": ";
		if (idx == 8)   //����м�ķָ���
			cout << " -";

		output_hex(ch); //ʮ�����������ǰ�ֽ�

		if (idx == 15)
			output_char(idx, row, 1);  //��16�������һ��
	}

	in_file.close();
	return 0;
}