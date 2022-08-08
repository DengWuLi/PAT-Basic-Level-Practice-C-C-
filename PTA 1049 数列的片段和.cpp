/* PTA 1049 数列的片段和
 * 2022/08/08
 * 注: 此题使用double类型保存结果存在精度误差
 * */
 
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	double temp;
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		sum += (long long)(temp * 1000) * (N - i) * (i + 1);
	}
	printf("%.2f\n", sum / 1000.0);
}
