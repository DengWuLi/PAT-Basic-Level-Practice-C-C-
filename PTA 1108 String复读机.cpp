/* PTA 1108 String复读机
 * 2022/07/30
 * */

#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int a[6] = {0};
	for (char i : str)
	{
		if (i == 'S')
			a[0]++;
		else if (i == 't')
			a[1]++;
		else if (i == 'r')
			a[2]++;
		else if (i == 'i')
			a[3]++;
		else if (i == 'n')
			a[4]++;
		else if (i == 'g')
			a[5]++;
	}
	while (true)
	{
		if (a[0] > 0)
		{
			cout << "S";
			a[0]--;
		}
		if (a[1] > 0)
		{
			cout << "t";
			a[1]--;
		}
		if (a[2] > 0)
		{
			cout << "r";
			a[2]--;
		}
		if (a[3] > 0)
		{
			cout << "i";
			a[3]--;
		}
		if (a[4] > 0)
		{
			cout << "n";
			a[4]--;
		}
		if (a[5] > 0)
		{
			cout << "g";
			a[5]--;
		}
		
		int count = 0;
		for (int i : a)
			if (i == 0)
				count++;
		if (count == 6)
			break;
	}
}