/* PTA 1007 素数对猜想
 * 2022/07/22
 * */
#include<iostream>
#include<cmath>
using namespace std;

int judge(int n)
{
	int b = 0;
	for (int i = 2; i <= static_cast<int>(sqrt(n)) + 1; i++)
	{
		if (n % i == 0)
		{
			b = 0;
			break;
		}//如果n是合数则返回0.
		else b = 1;
	}
	return b;
}
int main()
{
	int a;
	cin >> a;
	int *p = new int[a + 1];
	p[0] = 0;
	p[1] = 0;
	p[2] = 1;
	for (int i = 3; i < a + 1; i++)
		p[i] = judge(i);
	int count = 0;
	for (int i = 2; i <= a - 2; i++)
	{
		if (p[i] == 1 && p[i + 2] == 1)
			//cout << "(" << i << " " << i + 2 << ")"<<endl;
			count++;
	}
	cout << count;
}