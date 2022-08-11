/* PTA 1090 危险品装箱
 * 2022/08/10
 * 注, 一个物品, 可能和多个物品不能共存
 * 使用map果然好用, 借鉴了大佬的代码
 * */

#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int kMax = 100000;

int main()
{
	int N, M;
	cin >> N >> M;
	
	map<int, vector<int>> items;
	int temp_1, temp_2;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_1 >> temp_2;
		items[temp_1].push_back(temp_2);
		items[temp_2].push_back(temp_1);
	}
	int K;
	
	for (int i = 0; i < M; i++)
	{
		cin >> K;
		int a[K + 1];
		int b[kMax] = {0};
		for (int j = 0; j < K; j++)
		{
			cin >> a[j];
			b[a[j]] = 1;  //记录是否出现过此物品.
		}
		bool flag = false;
		
		for (int j = 0; j < K && !flag; j++)
		{
			for (int k : items[a[j]])
			{
				if (b[k] == 1)
				{
					flag = true;
					break;
				}
			}
		}
		
		if (flag)
			cout << "No" << "\n";
		else
			cout << "Yes" << "\n";
	}
}
