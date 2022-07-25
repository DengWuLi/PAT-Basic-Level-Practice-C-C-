/* PTA 1081 检查密码
 * 2022/07/25
 * */

#include <iostream>
using namespace std;

void print(int flag)
{
	switch (flag)
	{
		case 1: cout << "Your password is wan mei.";  //密码合法
			break;
		case 2: cout << "Your password is tai duan le.";  //密码太短
			break;
		case 3: cout << "Your password is tai luan le.";  //码长度合法，但存在不合法字符
			break;
		case 4: cout << "Your password needs shu zi.";  //密码长度合法，但只有字母没有数字
			break;
		case 5: cout << "Your password needs zi mu.";  //密码长度合法，但只有数字没有字母
			break;
	}
	cout << "\n";
}

int main()
{
	int N;
	cin >> N;
	getchar();
	while (N--)
	{
		string str;
		getline(cin, str);
		
		if (str.size() < 6)
		{
			print(2);
			continue;
		}
		
		int flag[4] = {0};
		for (char i : str)
		{
			if (isalpha(i))  //字母
				flag[0] = 1;
			else if (isalnum(i))  //数字
				flag[1] = 1;
			else if (i == '.')  //小数点
				flag[2] = 1;
			else  //其他字符
			{
				flag[3] = 1;
				break;
			}
		}
		if (flag[3] == 1)
			print(3);
		else if (flag[0] == 0)
			print(5);
		else if (flag[1] == 0)
			print(4);
		else
			print(1);
	}
}
