/*2152402 Èí¼ş ¶ÎæÃæÃ*/
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
	bool lamp[101];
	for (int i = 1;i <= 100;++i)
		lamp[i] = 0;

	for (int i = 1;i <= 100;++i)
		for (int j = 1;i * j <= 100;++j)
			lamp[i * j] ^= 1;

	for (int i = 1;i <= 100;++i)
		if (lamp[i])
			cout << i << " ";
	cout << endl;

	return 0;
}