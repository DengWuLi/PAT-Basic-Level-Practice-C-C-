/* PTA 1003 我要通过!
 * 2022/07/17
 * */
#include <iostream>
using namespace std;

bool judge(string s)
{
	int a[5] = {0};
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
			return false;
		if (s[i] == 'P')
		{
			a[0]++;
			if (a[1] != 0 || a[0] > 1)
				return false;
		}
		else if (s[i] == 'T')
		{
			a[1]++;
			if (a[0] == 0 || a[1] > 1)
				return false;
		}
		else
		{
			if (a[0] == 0 && a[1] == 0)
				a[2]++;
			else if (a[0] != 0 && a[1] == 0)
				a[3]++;
			else
				a[4]++;
		}
	}
	
	if (a[0] == 0 || a[1] == 0 || a[3] == 0)
		return false;
	else if (a[3] * a[2] != a[4])
		return false;
	else
		return true;
	
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (judge(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}