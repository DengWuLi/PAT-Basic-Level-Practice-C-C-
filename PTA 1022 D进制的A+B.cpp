/* PTA 1022 D进制的A+B
 * 2022/08/01
 * */

#include<iostream>
using namespace std;
int res[100];

int main()
{
	long long int A, B, C;
	int D;
	cin >> A >> B >> D;
	C = A + B;
	int i = 0;
	if (C == 0)
	{
		cout << 0;
		return 0;
	}
	while (C)
	{
		res[i++] = C % D;
		C /= D;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << res[j];
}
