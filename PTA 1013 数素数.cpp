/* PTA 1013 数素数
 * 2022/07/26
 * */

#include<iostream>
#include<cmath>
using namespace std;

int Judge(int n)
{
	int b = 0;
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
	{
		for (int i = 2; i <= static_cast<int>(sqrt(n)) + 1; i++)
		{
			if (n % i == 0)
			{
				b = 0;
				break;
			}//如果n是合数则返回0.
			else b = 1;
		}
		return b;
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	int count_1 = 0, count_2 = 0;  //conut1用于统计质数的个数，count2用于按格式输出
	for (int i = 1; count_1 < n; i++)
	{
		if (Judge(i) == 1)
		{
			count_1++;
			if (count_1 >= m)
			{
				cout << i;
				count_2++;
				if ((count_2 != 10) && (count_1 != n))
					cout << " ";
				else if (count_2 == 10)
				{
					cout << endl;
					count_2 = 0;
				}
			}
		}
	}
}