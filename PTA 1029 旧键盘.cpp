/* PTA 1029 旧键盘
 * 2022/08/02
 * */

#include <iostream>
using namespace std;

int main()
{
	string right, wrong;
	cin >> right >> wrong;
	int len_1 = right.size(), len_2 = wrong.size();
	int *ch = new int[len_1 - len_2 + 1];
	for (int i = 0; i < len_1; i++)
		right[i] = toupper(right[i]);
	for (int i = 0; i < len_2; i++)
		wrong[i] = toupper(wrong[i]);
	int k = 0;
	bool flag;
	for (int i = 0; i < len_1; i++)
	{
		flag = false;
		for (int j = 0; j < len_2; j++)
			if (wrong[j] == right[i])
			{
				flag = true;  //如果有相同的字符, 就把flag赋值为true;
				break;
			}
		if (!flag)
			ch[k++] = static_cast<int>(right[i]);
	}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (ch[i] == ch[j])
				ch[j] = -1;
	
	for (int i = 0; i < k; i++)
		if (ch[i] != -1)
			printf("%c", ch[i]);
}