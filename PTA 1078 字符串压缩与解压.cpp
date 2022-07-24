/* PTA 1078 字符串压缩与解压
 * 2022/07/24
 * */
#include <iostream>
using namespace std;

int main()
{
	char a;
	cin >> a;  //如果是 C 就表示下面的字符串需要被压缩; 如果是 D 就表示下面的字符串需要被解压.
	getchar();
	string str;
	int count;
	
	if (a == 'C')  //表示压缩
	{
		getline(cin, str);
		for (int i = 0; i < str.size();)
		{
			char temp = str[i];
			count = 0;
			while (true)
			{
				if (str[count + i] == temp)
					count++;
				else
				{
					if (count == 1)
					{
						cout << str[i];
						i++;  //如果没有重复的字符, 则 i向前移动一个单位
					}
					else
					{
						cout << count << str[i];
						i = i + count;
					}
					break;
				}
			}
		}
	}
	else if (a == 'D')  //表示解压
	{
		getline(cin, str);
		for (int i = 0; i < str.size();)
		{
			char temp = str[i];
			char temp2 = temp;
			count = 0;  //记录数字位数
			string temp3;  //用于记录数字
			if (!(temp >= '0' && temp <= '9'))
			{
				cout << temp;
				i++;  //移动到下一位
				continue;
			}
			
			while (true)
			{
				if (temp2 >= '0' && temp2 <= '9')
				{
					count++;
					temp3 += temp2;
					temp2 = str[i + count];
				}
				else
				{
					count--;  //表示记录位数减一
					break;
				}
			}
			
			int temp4 = stoi(temp3);  //将字符串数字转化为整数
			for (int j=0; j < temp4; j++)
				cout << str[i + count + 1];
			i = i + count + 2;
		}
	}
}