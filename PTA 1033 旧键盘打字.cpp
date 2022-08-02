/* PTA 1033 旧键盘打字
 * 2022/08/02
 * */

#include <iostream>
using namespace std;

int main()
{
	string Broken, in;
	getline(cin, Broken);
	getline(cin, in);
	bool flag1 = false, flag;
	for (char i : Broken)
		if (i == '+')
			flag1 = true;  //表示上档键坏掉了
	for (char i : in)
	{
		flag = false;
		for (char j : Broken)
			if (towupper(i) == j)
			{
				flag = true;
				break;
			}
			else if (i >= 'A' && i <= 'Z' && flag1)
			{
				flag = true;
				break;
			}
		if (!flag)
			cout << i;
	}
	printf("\n");
}
