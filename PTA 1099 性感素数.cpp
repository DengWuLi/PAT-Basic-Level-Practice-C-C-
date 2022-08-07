/* PTA 1099 性感素数
 * 2022/08/07
 * 注: 本以为这道题目会有一些奇妙的解法, 没想到这么简单就解决了, 有些意外.
 * */

#include <iostream>
#include <valarray>
using namespace std;

bool Judge(int N)
{
	if (N == 1 || N <= 0)
		return false;
	else if (N == 2)
		return true;
	for (int i = 2; i < sqrt(N) + 1; i++)
		if (N % i == 0)
			return false;
	return true;
}
int main()
{
	int N;
	cin >> N;
	if (Judge(N) && Judge(N - 6))
	{
		cout << "Yes" << "\n";
		cout << N - 6;
	}
	else if (Judge(N) && Judge(N + 6))
	{
		cout << "Yes" << "\n";
		cout << N + 6;
	}
	
	else
	{
		cout << "No" << "\n";
		for (int i = N;; i++)
		{
			if (Judge(i) && (Judge(i + 6) || Judge(i - 6)))
			{
				cout << i;
				break;
			}
		}
	}
	
}
