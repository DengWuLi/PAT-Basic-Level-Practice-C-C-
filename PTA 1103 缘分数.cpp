/* PTA 1103 缘分数
 * 2022/07/30
 * */

#include <iostream>
#include <valarray>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int count = 0;  //用于记录缘分数的个数
	for (long long int i = m; i <= n; i++)
	{
		long long int a, b, temp;
		a = pow(i, 3) - pow(i - 1, 3);
		temp = (sqrt(a));
		if (temp * temp != a)  //表示不是完全平方数
			continue;
		for (int j = temp - 1; j > 0; j--)
		{
			b = pow(j, 2) + pow(j - 1, 2);
			if (temp == b)
			{
				count++;
				printf("%d %d\n", i, j);
			}
		}
	}
	if (count == 0)
		cout << "No Solution" << "\n";
}