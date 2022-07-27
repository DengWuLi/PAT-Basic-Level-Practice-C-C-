/* PTA 1047 编程团体赛
 * 2022/07/27
 * */

#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int team[1005] = {0};
	int team_num, person, grade;
	for (int i = 0; i < N; i++)
	{
		scanf("%d-%d %d", &team_num, &person, &grade);
		team[team_num] += grade;
	}
	int MaxNum, Maxgrade = -1;
	for (int i = 1; i < 1001; i++)
		if (team[i] > Maxgrade)
		{
			Maxgrade = team[i];
			MaxNum = i;
		}
	cout << MaxNum << " " << Maxgrade;
}
