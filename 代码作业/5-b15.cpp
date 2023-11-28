/*2152402 软件 段婷婷*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];
	int cnt[5];
	for (int i = 0;i < 5;++i)
		cnt[i] = 0;

	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128, '\n');

	for (int i = 0;i < 3;++i)
		for (int j = 0;str[i][j] != '\0';++j)
		{
			char ch = str[i][j];
			if (ch >= 'a' && ch <= 'z')
				++cnt[0];
			else if (ch >= 'A' && ch <= 'Z')
				++cnt[1];
			else if (ch >= '0' && ch <= '9')
				++cnt[2];
			else if (ch == ' ')
				++cnt[3];
			else
				++cnt[4];
		}

	cout << "大写 : " << cnt[1] << endl;;
	cout << "小写 : " << cnt[0] << endl;
	cout << "数字 : " << cnt[2] << endl;
	cout << "空格 : " << cnt[3] << endl;
	cout << "其它 : " << cnt[4] << endl;

	return 0;
}
/*
Welcome to Tongji University.
<Hello,world!> -> 《Hello，world！》
Name=张三 and No=2059999 && Sex=男
*/