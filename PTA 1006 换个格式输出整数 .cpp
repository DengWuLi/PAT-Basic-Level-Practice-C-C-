/* PTA 1006 换个格式输出整数
 * 2022/07/21
 * */
#include<iostream>
#include<string.h>
using namespace std;

void fun1(int a)
{
	for (int i = 0; i < a; i++)
		cout << 'B';
}

void fun2(int a)
{
	for (int i = 0; i < a; i++)
		cout << 'S';
}

void fun3(int a)
{
	for (int i = 1; i <= a; i++)
		cout << i;
}

int main()
{
	char ch[3];
	cin >> ch;
	int a = strlen(ch);
	switch (a)
	{
		case 3: fun1(static_cast<int>(ch[0]) - 48);
			fun2(static_cast<int>(ch[1]) - 48);
			fun3(static_cast<int>(ch[2]) - 48);
			break;
		case 2: fun2(static_cast<int>(ch[0]) - 48);
			fun3(static_cast<int>(ch[1]) - 48);
			break;
		case 1: fun3(static_cast<int>(ch[0]) - 48);
			break;
		default:break;
	}
	
}