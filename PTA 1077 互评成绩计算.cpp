/* PTA 1077 互评成绩
 * 2022/07/30
 * */

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int a[N + 1];
	for (int i = 0; i < N; i++)
	{
		int temp;
		int sum = 0;
		int count = 0;
		int MAX = 0, MIN = M;
		int g_1;
		cin >> g_1;
		for (int j = 1; j < N; j++)
		{
			cin >> temp;
			if (temp > M || temp < 0)
				continue;
			else
			{
				count++;
				sum += temp;
				MAX = max(temp, MAX);
				MIN = min(temp, MIN);
			}
		}
		sum = sum - MIN - MAX;
		double g_2 = sum * 1.0 / (count - 2);
		double grade = (g_1 + g_2) / 2;
		if (grade - int(grade) >= 0.5)
			cout << int(grade) + 1;
		else
			cout << int(grade);
		cout << "\n";
	}
}