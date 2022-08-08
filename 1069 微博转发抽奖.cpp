/* 1069 微博转发抽奖
 * 2022/08/07
 * */

#include <iostream>
#include <map>
using namespace std;

int main()
{
	int M, N, S, cnt = 0;
	cin >> M >> N >> S;
	map<string, bool> mp;
	getchar();
	string a[M + 2];
	for (int i = 1; i <= M; i++)
		cin >> a[i];
	for (int i = S; i <= M; i += N)
	{
		if (!mp[a[i]])
		{
			mp[a[i]] = true;
			cnt++;
			cout << a[i] << "\n";
		}
		else
			i = i - N + 1; //因为每次i都要加n所以要回到i-n+1的位置, 之后自动加n, 即到了最后原始i之前的一个位置
	}
	if (cnt == 0)
		cout << "Keep going...";
}