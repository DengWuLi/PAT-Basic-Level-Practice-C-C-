/* 2022/08/29
 * PTA 1087 有多少不同的值
 * */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    bool flag[100000] = {false};
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        int temp = floor(i / 2) + floor(i / 3) + floor(i / 5);
        if (!flag[temp])  //如果这个数字没有出现的话
            count++;
        flag[temp] = true;
    }
    cout << count;
}