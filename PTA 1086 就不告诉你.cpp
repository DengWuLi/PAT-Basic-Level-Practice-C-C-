/* PTA 1086 就不告诉你
 * 2022/07/26
 * 注:此题不要输出前导0, 即乘积为100, 应输出1, 而不是001, 这一点在题目中并未说明
 * */

#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int C = A * B;
	if(C==0)
	{
		cout<<0;
		return 0;
	}
	string str = to_string(C);  //数字转字符串
	bool flag = true;  //默认有前导零
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == '0' && flag)
			continue;
		else
		{
			cout << str[i];
			flag = false;
		}
	}
}