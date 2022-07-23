/* PTA 1053 住房空置率
 * 2022/07/23
 * */

#include <iostream>
using namespace std;

int main()
{
	int N;
	double e;
	int D;
	int may_be_vacant = 0, vacant = 0;
	int K;
	int day;
	double temp;
	cin >> N >> e >> D;
	
	for (int i = 0; i < N; i++)
	{
		cin >> K;
		day = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			if (temp < e)
				day++;
		}
		
		if (day * 2 > K && K > D)  //在超过一半的日子用电量低于某给定的阈值 e, 且观察期 K超过D, 则为 vacant
			vacant++;
		else if (day * 2 > K)
			may_be_vacant++;
	}
	
	printf("%.1f\%% %.1f%%", may_be_vacant * 100.0 / N, vacant * 100.0 / N);
	
}
