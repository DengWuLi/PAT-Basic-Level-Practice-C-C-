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

/// PTA 1032 挖掘机技术哪家强
/// 2023/01/07
/// 使用STL复写了一下, 如果使用 C++的cin与cout语句最后一个测试点将有50ms, 而使用 C的scanf与printf则会缩短到30ms以内.

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    unordered_map<int, int> schools;
    int maxName, maxScore = -1;
    int tempScore, tempName;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &tempName, &tempScore);
        if (schools.find(tempName) == schools.end())
            schools.insert({ tempName, tempScore });
        else
            schools[tempName] += tempScore;
        if (maxScore < schools[tempName])
        {
            maxScore = schools[tempName];
            maxName = tempName;
        }
    }
    printf("%d %d\n", maxName, maxScore);
}
