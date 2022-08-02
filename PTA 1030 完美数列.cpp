/* PTA 1030 完美数列
 * 2022/08/02
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N,p;
	cin>>N>>p;
	auto *a=new long long int[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	sort(a,a+N);
	int count=0;  //表示覆盖范围
	for(int i=0;i<N;i++)
		for(int j=i+count;j<N;j++)
		{
			if (a[j] > p * a[i])  //不符合成立条件, 直接break;
				break;
			count=max(count,j-i+1);  //取count与现在范围的最大值
		}
	cout<<count;
}
