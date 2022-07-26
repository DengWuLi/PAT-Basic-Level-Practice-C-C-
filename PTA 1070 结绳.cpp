/* PTA 1070 结绳
 * 2022/07/26
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a[N + 1];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	int sum = a[0];  //记得此处要让sum的初始值为a[0]
	for (int i = 0; i < N; i++)
		sum = (sum + a[i]) / 2;
	cout << sum;
}