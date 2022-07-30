/* PTA 1056 组合数的和
 * 2022/07/30
 * */

#include <iostream>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	cin>>N;
	char a[N + 1];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j)
				sum += 10 * (a[i] - '0') + a[j] - '0';
	cout << sum;
}