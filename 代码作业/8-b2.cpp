/*2152402 软件 段婷婷*/
/*2151350 李静芝 2152871 王颢瑾 2151804 臧若曦 2153000 汪乘羽 2152520 林奕飞 */
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const int N = 500;

void input(char* infile_name, char* outfile_name) {
	cerr << "文件名以下形式均可以:" << endl;
	cerr << "    a.txt                    : 不带路径形式" << endl;
	cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
	cerr << "请输入要转换的hex格式文件名 : ";
	cin.getline(infile_name, N - 1);
	cerr << "请输入转换后的文件名        : ";
	cin.getline(outfile_name, N - 1);
}

int trans(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return -1;
}
int main() {

	char infile_name[N], outfile_name[N];
	input(infile_name, outfile_name);
	
	ifstream in_file(infile_name, ios::in);
	ofstream out_file(outfile_name, ios::out|ios::binary);

	if (!in_file.is_open()) {
		cout << "输入文件" << infile_name << "打开失败！" << endl;
		return 0;
	}
	if (!out_file.is_open()) {
		cout << "输出文件" << outfile_name << "打开失败！" << endl;
		return 0;
	}

	while (in_file.peek() != EOF) {
		long long pos = 0;
		for (int i = 0;i < 8;++i) {
			int x = in_file.get();
			pos = pos * 16 + trans(x);
		}
		if (pos != out_file.tellp()) {
			cout << "最左侧的偏移量0x" << setfill('0') << setw(8) << hex << pos << "不是期望值0x" << setfill('0') << setw(8) << hex << out_file.tellp() << endl;
			return 0;
		}
		
		int num = 0;
		//in_file.seekg(3, ios::cur);
		for (int i = 0;i < 3;++i)
			in_file.get();

		for (int i = 0;i < 8;++i) {
			char ch1 = in_file.get(), ch2 = in_file.get();
			in_file.get();
			//in_file.seekg(1, ios::cur);
			if (ch1 != ' ') {
				out_file.put(trans(ch1) * 16 + trans(ch2));
				++num;
			}
		}

		in_file.get();
		in_file.get();
		//in_file.seekg(2, ios::cur);

		for (int i = 8;i < 16;++i) {
			char ch1 = in_file.get(), ch2 = in_file.get();
			in_file.get();
			//in_file.seekg(1, ios::cur);
			if (ch1 != ' ') {
				out_file.put(trans(ch1) * 16 + trans(ch2));
				++num;
			}
		}

		for (int i = 0;i <= num + 1;++i)
			in_file.get();
	}

	in_file.close();
	out_file.close();

	return 0;
}