/*2152402 Èí¼ş ¶ÎæÃæÃ*/
#include<iostream>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?"; //¹² 15 ¸öÓ¢ÎÄ·ûºÅ 

int tj_strlen(const char str[])
{
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}

int main()
{
	int len, num[4], totnum = 0;
	char s[100];
	cin.get(s,99, '\n');
	cin >> len;
	for (int i = 0;i < 4;++i)
		cin >> num[i];
	for (int k = 0;k < 10;++k)
	{
		cin >> s;
		int len1 = tj_strlen(s);
		if (len1 != len)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		int num1[4] = { 0,0,0,0 };
		for (int i = 0;i < len1;++i)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				++num1[0];
			else if (s[i] >= 'a' && s[i] <= 'z')
				++num1[1];
			else if (s[i] >= '0' && s[i] <= '9')
				++num1[2];
			else
			{
				bool tag = 0;
				for (int j = 0;j < 15;++j)
					if (other[j] == s[i])
					{
						tag = 1;
						++num1[3];
						break;
					}
				if (!tag)
				{
					cout << "´íÎó" << endl;
					return 0;
				}
			}
		}
		for (int i = 0;i < 4;++i)
			if (num1[i] < num[i])
			{
				cout << "´íÎó" << endl;
				return 0;
			}
	}
	cout << "ÕıÈ·" << endl;
	return 0;
}