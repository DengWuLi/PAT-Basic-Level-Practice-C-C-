/* PTA 1017 A除以B
 * 2022/08/01
 * */

#include<iostream>
using namespace std;

int main()
{
	string A;
	int B;
	cin >> A >> B;
	int len = A.size();
	int Q = (A[0] - '0') / B;
	if (len == 1 || (Q != 0 && len > 1))
		cout << Q;
	int R = (A[0] - '0') % B;  //初始化
	for (int i = 1; i < len; i++)
	{
		cout << (R * 10 + A[i] - '0') / B;
		R = (R * 10 + A[i] - '0') % B;
	}
	cout << " " << R;
}
