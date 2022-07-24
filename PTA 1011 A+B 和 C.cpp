/* PTA 1011 A+B 和 C
 * 2022/07/25
 * */

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	const int T = t;
	long long A[T], B[T], C[T];
	for (int i = 0; i < T; i++)
		cin >> A[i] >> B[i] >> C[i];
	for (int i = 0; i < T; i++)
	{
		if ((A[i] + B[i]) > C[i])
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}
	return 0;
}
