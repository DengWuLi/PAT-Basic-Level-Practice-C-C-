/*  PTA 1001 害死人不偿命的(3n+1)猜想
    2022/07/17
*/
#include<iostream>
using namespace std;

int main()
{
	int N, i = 0;
	cin >> N;
	for (; N != 1; i++)
	{
		if (N % 2 == 0)
			N = N / 2;
		else
			N = (3 * N + 1) / 2;
	}
	cout << i;
	return 0;
}
