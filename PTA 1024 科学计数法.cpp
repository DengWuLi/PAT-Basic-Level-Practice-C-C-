/* PTA 1024 科学计数法
 * 2022/08/01
 * */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A;
	cin >> A;
	int posE = A.find('E'); //找到E所在的位置
	int exp = stoi(A.substr(posE + 1));  //将指数转换为真正的数
	string num = A.substr(1, posE - 1);  //将数字的绝对值单独复制到一个新字符串里面
	int posP = num.find('.');  //找到.的位置
	if (A[0] == '-')
		cout << A[0];
	if (A[posE + 1] == '+')  //向右移动小数点
	{
		if (posP + exp > num.size() - 1)  //移动小数点后, 新数字不带小数点
		{
			for (char i : num)
				if (i != '.')
					cout << i;
			for (int i = 0; i < exp - posP; i++)
				cout << 0;
		}
		else if (posP + exp == num.size() - 1)
		{
			for (char i : num)
				if (i != '.')
					cout << i;
		}
		else  //移动小数点后, 新数字依旧带带小数点, 其他位置正常输出, 只需在应该添加小数点的地方添加即可
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (num[i] != '.')
					cout << num[i];
				if (i == posP + exp)
					cout << '.';
			}
		}
		
	}
	else  //向左移动小数点
	{
		cout << "0.";  //先输出小数点, 再补零
		for (int i = 1; i <= abs(exp) - 1; i++)
			cout << 0;
		for (char i : num)
			if (i != '.')
				cout << i;
	}
}

