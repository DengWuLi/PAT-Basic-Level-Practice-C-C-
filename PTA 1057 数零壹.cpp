/* PTA 1057 数零壹
 * 2022/07/26
 * */

#include <iostream>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int N = 0;
	for (int i = 0; i < str.size(); i++)
		if (isalpha(str[i]))
			N += toupper(str[i]) - 'A' + 1;
	int count_0 = 0, count_1 = 0;
	while (N != 0)
	{
		if (N & 1)
			count_1++;
		else
			count_0++;
		N >>= 1;
	}
		cout << count_0 << " " << count_1;
}
