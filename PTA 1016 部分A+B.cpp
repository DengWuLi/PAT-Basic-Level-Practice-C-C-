/* PTA 1016 部分A+B
 * 2022/07/26
 * */

#include<iostream>
using namespace std;

int Fun(string A, string Da)
{
	int count = 0;
	for (int i = 0; i < A.size(); i++)
		if (A[i] == Da[0])
			count++;
	int Pa = 0;
	for (int i = 0; i < count; i++)
		Pa = Pa * 10 + Da[0] - '0';
	return Pa;
}

int main()
{
	string A, Da, B, Db;
	cin >> A >> Da >> B >> Db;
	cout << Fun(A, Da) + Fun(B, Db) << endl;
}