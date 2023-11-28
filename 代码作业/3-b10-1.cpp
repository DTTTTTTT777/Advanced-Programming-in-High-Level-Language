/*2152402 软件 段婷婷*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int num = 0;
	for (int i1 = 1;i1 <= 9;++i1)
		for (int i2 = 1;i2 <= 9;++i2)
		{
			if (i2 == i1)
				continue;
			for (int i3 = 1;i3 <= 9;++i3)
			{
				if (i3 == i1 || i3 == i2)
					continue;
				int i = i1 * 100 + i2 * 10 + i3;
				for (int j1 = i1;j1 <= 9;++j1)
				{
					if (j1 == i1 || j1 == i2 || j1 == i3)
						continue;
					for (int j2 = 1;j2 <= 9;++j2)
					{
						if (j2 == i1 || j2 == i2 || j2 == i3 || j2 == j1)
							continue;
						for (int j3 = 1;j3 <= 9;++j3)
						{
							if (j3 == i1 || j3 == i2 || j3 == i3 || j3 == j1 || j3 == j2)
								continue;
							int j = j1 * 100 + j2 * 10 + j3;
							if (i > j)
								continue;
							for (int k1 = j1;k1 <= 9;++k1)
							{
								if (k1 == i1 || k1 == i2 || k1 == i3 || k1 == j1 || k1 == j2 || k1 == j3)
									continue;
								for (int k2 = 1;k2 <= 9;++k2)
								{
									if (k2 == i1 || k2 == i2 || k2 == i3 || k2 == j1 || k2 == j2 || k2 == j3 || k2 == k1)
										continue;
									for (int k3 = 1;k3 <= 9;++k3)
									{
										if (k3 == i1 || k3 == i2 || k3 == i3 || k3 == j1 || k3 == j2 || k3 == j3 || k3 == k1 || k3 == k2)
											continue;
										int k = k1 * 100 + k2 * 10 + k3;
										if (j > k)
											continue;
										if (i + j + k == 1953)
										{
											++num;
											cout << "No." << setw(3) << num << " : " << i << "+" << j << "+" << k << "=" << 1953 << endl;
										}
									}
								}
							}

						}
					}
				}
			}
		}

	cout << "total=" << num << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}