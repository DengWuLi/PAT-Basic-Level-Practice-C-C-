/* PTA 1107 老鼠爱大米
 * 2022/07/21
 * */
#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int temp;
	int max_in_group, max_in_all = -1;
	for (int i = 0; i < N; i++)
	{
		max_in_group = -1;
		
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			if (temp > max_in_group)
				max_in_group = temp;
		}
		
		if (max_in_group > max_in_all)
			max_in_all = max_in_group;
		
		cout << max_in_group;
		if (i != N - 1)
			cout << " ";
	}
	cout << "\n" << max_in_all;
}