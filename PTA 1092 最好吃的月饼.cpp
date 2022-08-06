/* PTA 1092 最好吃的月饼
 * 2022/08/06
 * 直播时做题, 遇到了邓与郭
 * */

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int a[N + 1];
	for (int i = 0; i < N; i++)
		a[i] = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			a[j] += temp;
		}
	
	int _max = -1;
	for (int i = 0; i < N; i++)
		_max = max(_max, a[i]);
	cout << _max << "\n";
	bool flag = 0;
	for (int i = 0; i < N; i++)
		if (_max == a[i])
		{
			if (!flag)
			{
				cout << 1 + i;
				flag = true;
			}
			else
				cout << " " << 1 + i;
		}
}
