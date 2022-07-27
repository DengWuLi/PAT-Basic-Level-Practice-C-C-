/* PTA 1036 跟奥巴马一起编程
 * 2022/07/27
 * */

#include <iostream>
using namespace std;
int main()
{
	int N;
	char c;
	cin >> N >> c;
	for (int i = 0; i < N; i++)
		cout << c;
	cout << "\n";
	double n = N * 1.0 / 2;
	int n1;
	if (n - int(n) >= 0.5)
		n1 = int(n) + 1;
	else
		n1 = int(n);
	for (int i = 0; i < n1 - 2; i++)
	{
		cout << c;
		for (int j = 0; j < N - 2; j++)
			cout << " ";
		cout << c;
		cout << "\n";
	}
	for (int i = 0; i < N; i++)
		cout << c;
}
