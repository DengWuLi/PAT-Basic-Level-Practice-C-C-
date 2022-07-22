/* PTA 1106 2019数列
 * 2022/07/21
 * */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1005] = {0, 2, 0, 1, 9};
	for (int i = 5; i <= 1000; i++)
	{
		int temp = 0;
		for (int j = 1; j <= 4; j++)
			temp += a[i - j];
		a[i] = temp % 10;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i];
}
