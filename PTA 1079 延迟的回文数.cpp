/* PTA 1079 延迟的回文数
 * 2022/08/09
 * 没想到此题竟然要自己写一个近似高精度的算法
 * */

#include <iostream>
using namespace std;

bool Judge(string str)
{
	for (int i = 0; i < str.size() / 2; i++)
		if (str[i] != str[str.size() - i - 1])
			return false;
	return true;
}

string Reverse(string str)
{
	string temp;
	for (int i = str.size() - 1; i >= 0; i--)
		temp += str[i];
	return temp;
}

string Add(const string &str_1, const string &str_2)
{
	int size = str_1.size() - 1;  //按照序号.
	int a[size + 2];
	for (int i = 0; i < size + 2; i++)
		a[i] = 0;
	for (int i = 0; i <= size; i++)
	{
		a[i] += str_1[i] - '0' + str_2[i] - '0';
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	a[size + 1] += a[size] / 10;
	a[size] %= 10;

	string temp;
	for (int i = size + 1; i >= 0; i--)
		if (i == size + 1 && a[i] == 0)
			continue;
		else
			temp += a[i] + '0';
	return temp;
}

int main()
{
	string n;
	cin >> n;
	string str = n;
	int cnt = 0;
	while (true)
	{
		if (Judge(str) && cnt < 10)
		{
			cout << str << " is a palindromic number.";
			break;
		}
		if (cnt >= 10)
		{
			cout << "Not found in 10 iterations.";
			break;
		}
		string temp = Reverse(str);
		string temp_2 = Add(str, temp);
		cout << str << " + " << temp << " = " << temp_2 << "\n";
		str = temp_2;
		cnt++;
	}
}
