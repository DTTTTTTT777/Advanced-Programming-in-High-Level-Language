/*2152402 Èí¼ş ¶ÎæÃæÃ*/
#include<iostream>
using namespace std;
int main()
{
	srand(time(0));
	char map[10][26];
	for (int i = 0;i < 10;++i)
		for (int j = 0;j < 26;++j)
			map[i][j] = 0;

	for (int k = 0;k < 50;++k)
	{
		while (1)
		{
			int x = rand() % 10, y = rand() % 26;
			if (map[x][y] == '*')
				continue;
			map[x][y] = '*';
			break;
		}
	}

	for (int x = 0;x < 10;++x)
		for (int y = 0;y < 26;++y)
		{
			if (map[x][y] == '*')
				continue;
			map[x][y] = '0';
			for (int i = max(0, x - 1);i <= min(9, x + 1);++i)
				for (int j = max(0, y - 1);j <= min(25, y + 1);++j)
					if (map[i][j] == '*')
						map[x][y] += 1;
		}
	for (int i = 0;i < 10;++i)
	{
		for (int j = 0;j < 26;++j)
			cout << map[i][j] << " ";
		cout << endl;
	}
	return 0;
}