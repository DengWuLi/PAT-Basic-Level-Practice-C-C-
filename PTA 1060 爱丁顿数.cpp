/* PTA 1060 爱丁顿数
 * 2022/08/16
 * 注: 参考其他人的代码
 * */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Pred(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    const int n = N + 1;
    vector<int> a(N+1);
    for (int i = 0; i < N; i++)
      cin >> a[i];
    sort(a.begin(), a.end(), Pred);
    int out = 0;
    int E = a[0];  //E初始值设为最大
    int i = 0;  //保存数组的位置
    while (i < N && E > 0)
    {
        while (i < N && a[i] > E)
            i++;
        int E_num = i;
        if (E_num >= E && out < E)
            out = E;
        E--;
    }
    cout << out;
}
