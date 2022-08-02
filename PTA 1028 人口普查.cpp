/* PTA 1026 人口普查
 * 2022/08/02
 * */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string input_name, input_birthday;
	string max_birthday = "1814/09/06", min_birthday = "2014/09/06", max_name, min_name;
	int n;
	cin >> n;
	int count = 0;
	while (n--)
	{
		cin >> input_name >> input_birthday;
		if (input_birthday <= "2014/09/06" && input_birthday >= "1814/09/06")
		{
			count++;
			if (input_birthday > max_birthday)  //出生日期晚于,年龄小
			{
				min_name = input_name;
				max_birthday = input_birthday;
			}
			if (input_birthday < min_birthday)  //出生日期早于,年龄大
			{
				max_name = input_name;
				min_birthday = input_birthday;
			}
		}
	}
	cout << count;
	if (count > 0)
		cout << " " << max_name << " " << min_name;
}
