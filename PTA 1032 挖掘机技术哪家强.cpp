/* PTA 1032 挖掘机技术哪家强
 * 2022/08/02
 * */

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int school[100005] = {0};
	int Num, Grade;
	int Max = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> Num >> Grade;
		school[Num] += Grade;
	}
	int k;
	for (int i = 1; i <= n; i++)
	{
		if (school[i] > Max)
		{
			Max = school[i];
			k = i;
		}
	}
	cout << k << " " << Max;
}
