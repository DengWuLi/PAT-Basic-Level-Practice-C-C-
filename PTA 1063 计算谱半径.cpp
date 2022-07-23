/* PTA 1063 计算谱半径
 * 2022/07/23
 * */

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int a, b;
	double mo, res = 0.0;
	while (N--)
	{
		cin >> a >> b;
		mo = sqrt(a * a + b * b);
		if (mo > res)
			res = mo;
	}
	printf("%.2f", res);
}
