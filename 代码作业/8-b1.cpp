/*2152402 软件 段婷婷*/
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int N = 500;

void input(char* file_name) {
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                    : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入文件名 : ";
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
		cout << "输入文件" << file_name << "打开失败!" << endl;
		return 0;
	}

	int idx = -1, row[20];
	cout << setiosflags(ios::uppercase); //十六进制输出时大写
	while (1) {
		int ch = in_file.get(); //读一个字节
		idx = (idx + 1) % 16;  //下标++
		row[idx] = ch;           //存到数组row

		if (ch == EOF) {
			if (idx > 0)
				output_char(idx, row, 0);  //把最后不满16个的一行输出
			break;
		}

		if (idx == 0)   //输出8位的位置
			cout << setfill('0') << setw(8) << hex << int(in_file.tellg()) - 1 << ": ";
		if (idx == 8)   //输出中间的分隔符
			cout << " -";

		output_hex(ch); //十六进制输出当前字节

		if (idx == 15)
			output_char(idx, row, 1);  //满16个，输出一行
	}

	in_file.close();
	return 0;
}