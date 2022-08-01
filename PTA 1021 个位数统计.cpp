/* PTA 1021 个位数统计
 * 2022/08/01
 * */

#include<iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = str.size();
	int count_1;
	for (int i = 0; i <= 9; i++)
	{
		count_1 = 0;
		for (int j = 0; j < len; j++)
			if (str[j] - '0' == i)
				count_1++;
		if (count_1)
			printf("%d:%d\n", i, count_1);
	}
}
