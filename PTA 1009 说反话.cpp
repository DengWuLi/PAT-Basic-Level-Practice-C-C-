/* PTA 1009 说反话
 * 2022/07/24
 * */
#include<iostream>
using namespace std;
int main()
{
	char a[81];
	cin.getline(a, 81, '\n');
	char p[80][80] = {'\0'};
	int count = 0;
	int i = 0;  //
	int y = 0;
	while (a[i] != '\0')
	{
		for (; (a[i] != ' ') && (a[i] != '\0'); y++, i++)
			p[count][y] = a[i];
		p[count][y] = '\0';
		count++;
		if (a[i] != '\0')
			i++;
		y = 0;
	}
	for (int j = count - 1; j > 0; j--)
		cout << p[j] << " ";
	cout << p[0];
	
}