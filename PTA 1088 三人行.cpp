/* PTA 1088 三人行
 * 2022/07/24
 * */

#include <iostream>
using namespace std;

int M;  //将M设置为全局变量, 方便写函数
void print(double t)  //输出部分复用率高, 特地写此函数
{
	if (M == t)
		cout << " Ping";
	else if (M < t)
		cout << " Cong";
	else
		cout << " Gai";
}
int main()
{
	int X, Y;
	cin >> M >> X >> Y;
	for (int i = 99; i >= 10; i--)  //i, j, k 分别代表甲乙丙三兄弟, 且从小到大遍历
	{
		int j = i % 10 * 10 + i / 10;
		int diff = abs(j - i);
		if (diff * Y == j * X)
		{
			double k = diff * 1.0 / X;
			cout << i;
			print(i);
			print(j);
			print(k);
			return 0;
		}
	}
	cout << "No Solution\n";
}
