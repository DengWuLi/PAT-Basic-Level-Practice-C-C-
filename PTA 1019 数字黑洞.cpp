/* PTA 1019 数字黑洞
 * 2022/08/01
 * */

#include<iostream>
#include<algorithm>
using namespace std;

int Fun(int a[])  //用于还原数组储存数字的数值大小
{
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}
void Fun1(int a[], int x)  //用于取出数值的每位数
{
	a[0] = x % 10, a[3] = x / 1000;  //个位和千位
	//a[1]=(x%100-x%10)/10,a[2]=(x%1000-x%100)/100;
	a[1] = x % 100 / 10, a[2] = x % 1000 / 100;
}
void Fun2(int x)
{
	//cout<<x/1000<<(x%1000-x%100)/100<<(x%100-x%10)/10<<x%10;
	cout << x / 1000 << x % 1000 / 100 << x % 100 / 10 << x % 10;
}
bool Cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int a[4], b[4];  //a数组用于储存非递增排序,b数组用于储存非递减排序
	int result, n;
	cin >> n;
	Fun1(a, n), Fun1(b, n);
	while (1)
	{
		sort(a, a + 4), sort(b, b + 4, Cmp);
		result = Fun(b) - Fun(a);
		if (result == 0)
		{
			cout << Fun(b) << " - " << Fun(a) << " = " << "0000" << endl;
			break;
		}
		else
		{
			Fun2(Fun(b));
			cout << " - ";
			Fun2(Fun(a));
			cout << " = ";
			Fun2(result);
			cout << endl;
		}
		if (result == 6174)
			break;
		Fun1(a, result), Fun1(b, result);
	}
}
