/* PTA 1018 锤子剪刀布
 * 2022/08/01
 * */

#include<iostream>
#include<algorithm>
using namespace std;

int A[6] = {0}, B[6] = {0};
void Judge(char a, char b)
{
	if (a == b) //表示A, B两名选手平局的情况
		A[1]++, B[1]++;
	else if (a == 'C' && b == 'J') //选手A出锤头, B出剪刀的情况
	{
		A[0]++, B[2]++;
		A[4]++;
	}
	else if (a == 'C' && b == 'B') //选手A出锤头, B出布的情况
	{
		A[2]++, B[0]++;
		B[5]++;
	}
	else if (a == 'J' && b == 'B') //选手A出剪刀, B出布的情况
	{
		A[0]++, B[2]++;
		A[3]++;
	}
	else if (a == 'J' && b == 'C') //选手A出剪刀, B出锤头的情况
	{
		A[2]++, B[0]++;
		B[4]++;
	}
	else if (a == 'B' && b == 'C') //选手A出布, B出锤头的情况
	{
		A[0]++, B[2]++;
		A[5]++;
	}
	else if (a == 'B' && b == 'J') //选手A出布, B出剪刀的情况
	{
		A[2]++, B[0]++;
		B[3]++;
	}
}

void Fun(int C[])
{
	int maxNumber = max(C[3], max(C[4], C[5]));
	int index;
	for (int i = 3; i < 6; i++)
		if (maxNumber == C[i])
			index = i;
	switch (index)
	{
		case 3:
			cout << 'J';
			break;
		case 4:
			cout << 'C';
			break;
		default:
			cout << 'B';
			break;
	}
}

int main()
{
	char a, b;
	int N;
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		Judge(a, b);
	}
	for (int i = 0; i < 3; i++)
	{
		cout << A[i];
		if (i != 2)
			cout << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << B[i];
		if (i != 2)
			cout << " ";
	}
	cout << endl;
	Fun(A);
	cout << " ";
	Fun(B);
	cout << endl;
}
