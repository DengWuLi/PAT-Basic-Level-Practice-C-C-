/* PTA 1023 组个最小数
 * 2022/08/01
 * */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int a[10];
	vector<int> b;
	int sum = 0;  //统计输入数字的总个数
	for (int & i : a)
	{
		cin >> i; //表示数字0~9的个数
		sum += i;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < a[i]; j++)
			b.push_back(i);
	}
	sort(b.begin(), b.end());
	cout << b[a[0]];
	for (int i = 0; i < a[0]; i++)
		cout << 0;
	for (int i = a[0] + 1; i < sum; i++)
		cout << b[i];
}
