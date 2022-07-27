/* PTA 1038 统计同成绩学生
 * 2022/07/27
 * */
#include <iostream>
using namespace std;
int main()
{
	int grades[100000+1]={0};
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int grade;
		cin>>grade;
		grades[grade]++;
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++)
	{
		int flag;
		cin>>flag;
		cout<<grades[flag];
		if(i!=K-1)
			cout<<" ";
	}
}
