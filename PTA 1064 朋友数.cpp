/* PTA 1064 朋友数
 * 2022/08/07
 * */

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int count[1001] = {0};
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		int sum = 0;
		for (char j : temp)
			sum += j - '0';
		count[sum]++;
	}
	int a = 0;
	for (int i = 0; i <= 1000; i++)
		if (count[i] != 0)
			a++;
	cout << a << "\n";
	bool flag = false;
	for (int i = 0; i <= 1000; i++)
		if (count[i] != 0)
		{
			if (!flag)
			{
				cout << i;
				flag = true;
			}
			else
				cout << " " << i;
		}
}
