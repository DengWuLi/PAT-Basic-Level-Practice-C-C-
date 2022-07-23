/* PTA 1010 一元多项式求导
 * 2022/07/24
 * */

#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "0 0";
		return 0;
	}
	else cout << a * b << " " << b - 1;
	while (cin >> a >> b)
		if (b != 0)
			cout << " " << a * b << " " << b - 1;
	return 0;
}