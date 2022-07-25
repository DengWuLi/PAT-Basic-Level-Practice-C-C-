/* PTA 1066 图像过滤
 * 2022/07/25
 * 注: 此题需要用scanf输入, 不然最后一个点会超时.
 * */

#include <iostream>
using namespace std;

int main()
{
	int M, N;
	int A, B, C;
	int temp;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &C);
	//cin >> M >> N >> A >> B >> C;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &temp);
			//cin >> temp;
			if (j != 0)
				cout << " ";
			if (temp >= A && temp <= B)
				printf("%03d", C);
			else
				printf("%03d", temp);
		}
		cout << "\n";
	}
}