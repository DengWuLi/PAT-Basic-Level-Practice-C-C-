/* PTA 1015 德才论
 * 2022/08/01
 * */

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct student
{
  string num;
  int de, cai, sum;
  int cla;
};
bool Cmp(student a, student b)
{
	if (a.cla != b.cla)
		return a.cla < b.cla;  //先按等级排序
	else if (a.sum != b.sum)
		return a.sum > b.sum;  //再按德才总分排序
	else if (a.de != b.de)
		return a.de > b.de;  //再按德分排序
	else  //最后按准考证号排序
		return a.num < b.num;
}

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	vector<student> stu(N);
	int count_1 = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i].num >> stu[i].de >> stu[i].cai;
		stu[i].sum = stu[i].de + stu[i].cai;
		if (stu[i].de < L || stu[i].cai < L)  //德分或才分小于L的, 不予录取
		{
			stu[i].cla = 5;
			count_1++;  //记录不合格人数
		}
		else if (stu[i].de >= H && stu[i].cai >= H)  //德才分均大于H
			stu[i].cla = 1;
		else if (stu[i].cai < H && stu[i].de >= H)  //才分小于H, 但德分大于H
			stu[i].cla = 2;
		else if (/*stu[i].cai<H&&stu[i].de<H&&*/stu[i].cai <= stu[i].de)  //才分和德分均小于H, 但德分大于才分
			stu[i].cla = 3;
		else  //其他通过及格线的考生
			stu[i].cla = 4;
	}
	sort(stu.begin(), stu.end(), Cmp);
	cout << N - count_1 << '\n';
	for (int i = 0; i < N - count_1; i++)
		cout << stu[i].num << " " << stu[i].de << " " << stu[i].cai << endl;
}

