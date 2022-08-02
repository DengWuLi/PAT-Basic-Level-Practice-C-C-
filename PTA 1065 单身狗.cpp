/* PTA 1065 单身狗
 * 2022/07/25
 * 注: 感觉这种以空间换时间的方法十分巧妙
 * */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a[99999 + 1];
	memset(a, -1, sizeof(a));
	int temp_1, temp_2;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_1 >> temp_2;
		a[temp_1] = temp_2;
		a[temp_2] = temp_1;
	}
	int M;
	cin >> M;
	int b[99999 + 1] = {0};
	int c[99999 + 1];
	for (int i = 0; i < M; i++)
	{
		cin >> b[i];  //记录出场名单
		c[b[i]] = 1;  //下标为ID, 记录出场
	}
	int count = 0;
	sort(b, b + M);  //排序
	for (int i = 0; i < M; i++)
		if (a[b[i]] == -1 || c[a[b[i]]] == 0)  //b[i]表示第i个人到场的ID, a[b[i]]表示第i个人对象的ID, c[a[b[i]]]判断第i个人的对象是否到场
			count++;
	
	cout<<count<<"\n";
	for (int i = 0; i < M; i++)
		if (a[b[i]] == -1 || c[a[b[i]]] == 0)
		{
			(void)printf("%05d",b[i]);
			if(i!=M-1)
				cout<<" ";
		}
}
