/* PTA 1020 月饼
 * 2022/08/01
 * */

#include<iostream>
#include<algorithm>
using namespace std;
struct moon_cake
{
  int a, b;  //a表示库存量, b表示总售价
  double price;
} m[1005];
bool Cmp(moon_cake x, moon_cake y)
{
	return x.price > y.price;
}

int main()
{
	int N, D;
	cin >> N >> D;
	double result = 0;
	for (int i = 0; i < N; i++)
		cin >> m[i].a;
	for (int i = 0; i < N; i++)
		cin >> m[i].b;
	for (int i = 0; i < N; i++)
		m[i].price = m[i].b * 1.0 / m[i].a;
	sort(m, m + N, Cmp);
	for (int i = 0; i < N; i++)
	{
		if (D >= m[i].a)
			result += m[i].b;
		else
		{
			result += m[i].price * D;
			break;
		}
		D = D - m[i].a;
	}
	printf("%.2f", result);
}
