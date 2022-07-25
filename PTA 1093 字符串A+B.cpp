/* PTA 1093 字符串A+B
 * 2022/07/25
 * 注: 感受, 感觉这种方式挺讨巧的.
 * */
//方法一:
#include <iostream>
using namespace std;

int main()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);
	string C = A + B;
	char a[128] = {0};
	for (int i = 0; i < C.size(); i++)
	{
		if (a[C[i]] == 0)
			cout << C[i];
		a[C[i]] = 1;
	}
}

//方法二:
#include <iostream>
#include<map>
using namespace std;

int main()
{
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);
	string C = A + B;
	map<char, int> m;  //类似Python中的键值对
	char a[10000];
	int j = 0;
	for (int i = 0; i < C.size(); i++)
	{
		if (m[C[i]] <= 0)
		{
			m[C[i]] = 1;  //表示C[i]这个字符已经出现过一次了.
			a[j++] = C[i];
		}
	}
	for (int i = 0; i < j; i++)
		cout << a[i];
	return 0;
}

