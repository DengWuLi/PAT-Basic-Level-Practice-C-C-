/* PTA 1094 谷歌的招聘
 * 2022/07/24
 * */

#include <iostream>
#include <cmath>
using namespace std;

bool Judge(int n)  //判断素数
{
	if (n == 1 || n == 0)
		return false;
	else if (n == 2)
		return true;
	for (int i = 2; i < sqrt(n) + 1; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int L, K;
	string N;
	cin >> L >> K;
	getchar();
	cin >> N;
	for (int i = 0; i <= L - K; i++)
	{
		string temp;
		for (int j = 0; j < K; j++)
			temp += N[i + j];
		int n = stoi(temp);
		if (Judge(n))
		{
			cout << temp;
			return 0;
		}
	}
	cout << 404;
}
