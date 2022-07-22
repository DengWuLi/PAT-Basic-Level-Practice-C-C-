/* PTA 1008 数组元素循环右移问题
 * 2022/07/23
 * */

#include<iostream>
using namespace std;

void reverse(int *p, int n)
{
	int temp = p[n - 1];
	for (int i = n - 1; i > 0; i--)
		p[i] = p[i - 1];  //从后向前赋值，有些类似于矩阵。从后一行加到前一行
	p[0] = temp;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int *p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < m; i++)
		reverse(p, n);
	for (int i = 0; i < n - 1; i++)
		cout << p[i] << " ";
	cout << p[n - 1];
}