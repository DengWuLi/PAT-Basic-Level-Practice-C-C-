/* PTA 1004 成绩排名
 * 2022/07/18
 * */
#include<iostream>
using namespace std;

struct student
{
  char name[11];
  char number[11];
  int score;
};

int main()
{
	int N;
	cin >> N;
	const int n = N;
	student stu[n];
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i].name >> stu[i].number >> stu[i].score;
	}
	student temp;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= N - 1 - i; j++)
		{
			if (stu[j].score > stu[j + 1].score)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	cout << stu[n - 1].name << " " << stu[n - 1].number << endl;
	cout << stu[0].name << " " << stu[0].number;
	
}