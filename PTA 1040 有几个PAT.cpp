/* PTA 1040 有几个PAT
 * 2023/01/03
 * 解题思路:
 * 1. 首先统计字符串中'T'的个数;
 * 2. 利用循环, 当遇到'P'时p++,遇到'T'时从t--,遇到'A'时, 总个数+=p*t
 * */


#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0, sum = 0;
    for (char i : str)
        if (i == 'T')
            t++;
    for (char i : str)
    {
        if (i == 'P')
            p++;
        else if (i == 'T')
            t--;
        else if (i == 'A')
            sum = (sum + (p * t) % 1000000007) % 1000000007;
    }
    cout<<sum << endl;
}
