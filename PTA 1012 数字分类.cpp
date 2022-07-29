/* PTA 1012 数字分类
 * 2022/07/29
 * */
#include <iostream>
#include <valarray>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int A[6] = {0};
	int j = 0, count = 0;
	bool flag = false;
	while (N--)
	{
		int temp;
		cin >> temp;
		int temp2 = temp % 5;
		switch (temp2)
		{
			case 0:
				if (temp % 2 == 0)
					A[1] += temp;
				break;
			case 1:  //交错求和结果可能为零或根本没有数据, 要分这两种情况讨论, 这一点比较坑
				j++;
				flag = true;
				A[2] += int(pow(-1, j - 1)) * temp;
				break;
			case 2:
				A[3]++;
				break;
			case 3:
				A[4] += temp;
				count++;
				break;
			case 4:
				A[5] = max(A[5], temp);
				break;
			default:
				break;
		}
	}
	double ave;
	if (count != 0)
		ave = double(A[4]) / count;
	for (int i = 1; i <= 5; i++)
	{
		if (i == 2)
		{
			if (flag)  //表示有这个数字
				cout << A[i];
			else
				cout << "N";
		}
		else if (i == 4)
		{
			if (A[i] == 0)
				cout << "N";
			else
				printf("%.1f", ave);
		}
		else
		{
			if (A[i] == 0)
				cout << "N";
			else
				cout << A[i];
		}
		if (i != 5)
			cout << " ";
	}
}