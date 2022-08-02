/* PTA 1027 打印漏斗
 * 2022/08/02
 * */

#include<iostream>
using namespace std;

int main()
{
	int N;
	char c;
	cin >> N >> c;
	int n = 0;
	while (2 * n * n - 1 <= N)  //计算最多的行数
		n++;
	n = n - 1;
	for (int i = n; i > 0; i--)  //输出上三角
	{
		for (int j = 0; j < n - i; j++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << c;
		cout << '\n';
	}
	for (int i = 2; i <= n; i++)  //输出下三角
	{
		for (int j = 0; j < n - i; j++)
			cout << " ";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << c;
		cout << '\n';
	}
	cout << N - (2 * n * n - 1);
}
