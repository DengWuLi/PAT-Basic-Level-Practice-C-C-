/* PTA 1083 是否存在相等的差
 * 2022/08/07
 * */

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int count[10005] = {0};
	int temp;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		count[abs(temp - i)]++;
	}
	for (int i = 9999; i >= 0; i--)  //注意差有可能为零
		if (count[i] >= 2)
			cout << i << " " << count[i] << "\n";
}