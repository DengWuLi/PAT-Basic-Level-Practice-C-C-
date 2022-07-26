/* PTA 1061 判断题
 * 2022/07/26
 * */

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int full_score[M + 1];
	int right_answer[M + 1];
	for (int i = 0; i < M; i++)
		cin >> full_score[i];
	for (int i = 0; i < M; i++)
		cin >> right_answer[i];
	int temp, grades = 0;
	for (int i = 0; i < N; i++)
	{
		grades = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			if (temp == right_answer[j])
				grades += full_score[j];
		}
		cout << grades << "\n";
	}
}