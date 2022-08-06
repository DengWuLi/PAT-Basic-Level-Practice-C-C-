/* PTA 1074 宇宙无敌加法器
 * 2022/07/31
 * */

#include <iostream>
using namespace std;

int main()
{
	string N;
	cin >> N;
	string N_1, N_2;
	cin >> N_1 >> N_2;
	int n_1[25] = {0}, n_2[25] = {0}, n[25] = {0};
	int j = 0;
	
	for (int i = N.size() - 1; i >= 0; i--)
		n[j++] = N[i] - '0';
	j = 0;
	for (int i = N_1.size() - 1; i >= 0; i--)
		n_1[j++] = N_1[i] - '0';
	j = 0;
	for (int i = N_2.size() - 1; i >= 0; i--)
		n_2[j++] = N_2[i] - '0';
	
	int n_3[25] = {0};
	for (int i = 0; i < 25; i++)
	{
		int temp = n_1[i] + n_2[i];
		int temp_2;
		if (n[i] == 0)
			temp_2 = 10;
		else
			temp_2 = n[i];
		n_3[i] = temp % temp_2;
		n_1[i + 1] += temp / temp_2;
	}
	j = -1;  //如果全都都为0, 测试点5的坑, 注意此处不应该设置一个为0的值, 不然只有最后一位不为0,依然会输出0
	for (int i = 24; i >= 1; i--)
		if (n_3[i] == 0 && n_3[i - 1] != 0)
		{
			j = i - 1;
			break;
		}
	if (j == -1)
	{
		cout << 0;
		return 0;
	}
	for (int i = j; i >= 0; i--)
		cout << n_3[i];
}
