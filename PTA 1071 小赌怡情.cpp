/* PTA 1071 小赌怡情
 * 2022/08/08
 * 注: 这个题有些坑, 要注意输出字符串的空格问题(是两个英文空格)
 * */

#include <iostream>
using namespace std;

int main()
{
	int T, K;
	cin >> T >> K;
	for (int i = 0; i < K; i++)
	{
		int n_1, b, t, n_2;
		cin >> n_1 >> b >> t >> n_2;
		
		if (T == 0)
		{
			cout << "Game Over.\n";
			break;
		}
		else if (t > T)
		{
			printf("Not enough tokens.  Total = %d.\n", T);
			continue;
		}
		
		if (n_1 < n_2)  //表示应该押大
		{
			if (b == 1)
			{
				T += t;
				printf("Win %d!  Total = %d.", t, T);
			}
			else
			{
				T -= t;
				printf("Lose %d.  Total = %d.", t, T);
			}
		}
		else
		{
			if (b == 0)
			{
				T += t;
				printf("Win %d!  Total = %d.", t, T);
			}
			else
			{
				T -= t;
				printf("Lose %d.  Total = %d.", t, T);
			}
		}
		cout << "\n";
	}
}
