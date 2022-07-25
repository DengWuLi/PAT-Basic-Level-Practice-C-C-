/* PTA 1072 开学寄语
 * 2022/07/25
 * */

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string str[M + 1];
	for (int i = 0; i < M; i++)
		cin >> str[i];
	int sum[2] = {0};
	for (int i = 0; i < N; i++)
	{
		string name;
		int K;
		cin >> name >> K;
		string temp;
		int count = 0;
		bool flag = true;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			
			for (int k = 0; k < M; k++)
			{
				if (temp == str[k])
				{
					sum[1]++;
					count++;
					flag = false;
					if (count == 1)
						cout << name << ":";
					cout << " " << temp;
				}
			}
			
		}
		if (!flag)
		{
			sum[0]++;
			cout << endl;
		}
	}
	cout << sum[0] << " " << sum[1];
}
