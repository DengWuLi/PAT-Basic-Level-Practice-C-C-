/* PTA 1031 查验身份证
 * 2022/08/02
 * */

#include <iostream>
using namespace std;

bool Judge(int a, char c)
{
	if (a == 0 && c == '1') return true;
	if (a == 1 && c == '0') return true;
	if (a == 2 && c == 'X') return true;
	if (a == 3 && c == '9') return true;
	if (a == 4 && c == '8') return true;
	if (a == 5 && c == '7') return true;
	if (a == 6 && c == '6') return true;
	if (a == 7 && c == '5') return true;
	if (a == 8 && c == '4') return true;
	if (a == 9 && c == '3') return true;
	if (a == 10 && c == '2') return true;
	return false;
}
int main()
{
	int N;
	cin >> N;
	string num;
	int a[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	bool f_1 = false, f_2 = true, f_3 = false;
	while (N--)
	{
		f_2 = true;  //必要的初始化
		cin >> num;
		for (int j = 0; j < 17; j++)
			if (num[j] < '0' || num[j] > '9')
			{
				f_2 = false;
				break;
			}
		if (f_2)  //如果输入合规, 即其中不含有字母
		{
			int Z = 0;
			for (int j = 0; j < 17; j++)
				Z += (num[j] - '0') * a[j];
			Z %= 11;
			f_3 = Judge(Z, num[17]);
		}
		if (f_2 && f_3)
			continue;
		else
		{
			cout << num << endl;
			f_1 = true;  //表示有输出
		}
	}
	if (!f_1)
		cout << "All passed";
}
