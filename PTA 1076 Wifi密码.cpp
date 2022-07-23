/* PTA 1076 Wifi密码
 * 2022/07/24
 * */
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	getchar();
	string temp1 = " ", temp2;
	while (N--)
	{
		getline(cin, temp2);
		temp1 = " ";  //将temp1置零
		temp1 += temp2;
		int i = 0;
		while (true)
		{
			if (temp1[i + 3] == 'T')
			{
				cout << int(temp1[i + 1] - 'A'+1);
				break;
			}
			else
				i += 4;
			if (i > temp1.size())
				break;
		}
	}
}
