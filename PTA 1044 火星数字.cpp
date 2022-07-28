/* PTA 1044 火星数字
 * 2022/07/26
 * */

#include <iostream>
using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void Encode(string str)
{
	int temp = stoi(str);
	if(temp==0)
		cout<<a[0];
	if (temp / 13 != 0)  //
	{
		cout << b[temp / 13];
		if (temp % 13 != 0)
			cout << " ";
	}
	if (temp % 13 != 0)
		cout << a[temp % 13];
	cout << "\n";
}

void Decode(string str)
{
	string temp;
	for (int i = 0; i < 3; i++)
		temp += str[i];
	int count = 0;
	for (int i = 0; i < 13; i++)
	{
		if (temp == b[i])  //第一个三位字母是高位
		{
			count += i * 13;
			if (str.size() < 4)  //表示只有一个三位字段
			{
				cout << count << "\n";
				return;
			}
			temp = "";
			for (int j = 4; j < str.size(); j++)
				temp += str[j];
			for (int j = 0; j < 13; j++)
				if (temp == a[j])
				{
					count += j;
					cout << count << "\n";
					return;
				}
		}
		
	}
	for (int i = 0; i < 13; i++)
		if (str == a[i])
		{
			cout << i << "\n";
			return;
		}
}

int main()
{
	int N;
	cin >> N;
	getchar();
	string str;
	while (N--)
	{
		getline(cin, str);
		if (isdigit(str[0]))
			Encode(str);
		else
			Decode(str);
	}
	
}
