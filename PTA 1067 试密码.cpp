/* PTA 1067 试密码
 * 2022/07/22
 * */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string password;
	int N;
	cin >> password >> N;
	getchar();  //需要一个getchar来吸收一个换行符
	int count = 0;
	string a;
	while (true)
	{
		getline(cin, a);  //此处输入密码时要整行读取, 因为密码中可能存在空格
		if (a == "#")
			return 0;
		
		if (a == password)
		{
			cout << "Welcome in";
			return 0;
		}
		else if (a != password)
		{
			cout << "Wrong password: " << a << endl;
			count++;
		}
		
		if (count == N)
		{
			cout << "Account locked";
			return 0;
		}
	}
}