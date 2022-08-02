/* PTA 1026 程序运行时间
 * 2022/08/02
 * */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int c_1, c_2;
	cin >> c_1 >> c_2;
	float c_3 = (c_2 * 1.0 - c_1) / 100;
	int h, m, s;
	h = c_3 / 3600;
	m = (c_3 - h * 3600) / 60;
	s = round(c_3 - h * 3600 - m * 60);
	if (s == 60)
	{
		m++;
		s = 0;
	}
	if (m == 60)
	{
		h++;
		m = 0;
	}
	printf("%02d:%02d:%02d", h, m, s);
}
