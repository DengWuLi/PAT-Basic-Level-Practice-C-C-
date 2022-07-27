/* PTA 1037 在霍格沃茨找零钱
 * 2022/07/27
 * */

#include <iostream>
using namespace std;
int main()
{
	int P[3], A[3];
	scanf("%d.%d.%d %d.%d.%d", &P[0], &P[1], &P[2], &A[0], &A[1], &A[2]);
	int R[3];
	for (int i = 0; i < 3; i++)
		R[i] = A[i] - P[i];
	while (!(R[2] >= 0 && R[2] < 29))
	{
		if (R[2] >= 29)
		{
			R[2] -= 29;
			R[1]++;
		}
		else if (R[2] < 0)
		{
			R[2] += 29;
			R[1]--;
		}
	}
	while (!(R[1] >= 0 && R[1] < 17))
	{
		if (R[1] >= 17)
		{
			R[1] -= 17;
			R[0]++;
		}
		else if (R[1] < 0)
		{
			R[1] += 17;
			R[0]--;
		}
	}
	if (R[0] < 0)
	{
		R[0]++;
		R[1] -= 17;
		R[1]++;
		R[2] -= 29;
	}
	if (R[0] < 0 || R[1] < 0 || R[2] < 0)
		printf("-%d.%d.%d", abs(R[0]), abs(R[1]), abs(R[2]));
	else
		printf("%d.%d.%d", R[0], R[1], R[2]);
}
