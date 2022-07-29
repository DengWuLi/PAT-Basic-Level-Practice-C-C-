/* PTA 1059 C语言竞赛
 * 2022/07/29
 * 注: 这段代码对一些点会运行超时, 可能需要二分搜索, 或者用空间换时间
 * */

#include <iostream>
#include <valarray>
using namespace std;

struct Student
{
  string ID;
  bool flag;
};

bool Judge(int n)
{
	if (n == 2 || n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int N;
	cin >> N;
	Student stu[N + 1];
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i].ID;
		stu[i].flag = false;  //表示没有领奖品
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		string temp;
		cin >> temp;
		bool flag = true;  //用于记录是否查有此人
		for (int j = 0; j < N; j++)
		{
			if (temp == stu[j].ID)  //如果能查到此姓名
			{
				flag = false;
				if (stu[j].flag)  //如果已经领奖
				{
					cout << temp << ": Checked";
					break;
				}
				else
				{
					if (j == 0)  //表示冠军
						cout << temp << ": Mystery Award";
					else if (Judge(j+1))
						cout << temp << ": Minion";
					else
						cout << temp << ": Chocolate";
				}
				
				stu[j].flag = true;  //标记为已经领过奖了.
				break;
			}
		}
		if (flag)
			cout << temp << ": Are you kidding?";
		cout << "\n";
	}
}

/* 可AC代码*/
#include <iostream>
#include <valarray>
using namespace std;

struct Student
{
  string ID;
  bool flag{false};   //在 C++上头一次见这种 struct形的初始化
  int rank{-1};
};

bool Judge(int n);

int main()
{
	Student stu[10000 + 1];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		stu[stoi(temp)].ID = temp;
		stu[stoi(temp)].rank = i + 1;
	}
	
	int K;
	cin >> K;
	while (K--)
	{
		string temp;
		cin >> temp;
		int temp_int = stoi(temp);
		if (stu[temp_int].rank != -1)  //表示查有此人
		{
			if (stu[temp_int].flag)  //如果已经领了礼物
				cout << temp << ": Checked";
			else
			{
				if (stu[temp_int].rank == 1)
					cout << temp << ": Mystery Award";
				else if (Judge(stu[temp_int].rank))  //如果是素数
					cout << temp << ": Minion";
				else
					cout << temp << ": Chocolate";
			}
			
			stu[temp_int].flag = true;
		}
		else
			cout << temp << ": Are you kidding?";
		cout << "\n";
	}
}
bool Judge(int n)
{
	if (n == 2 || n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
