/* PTA 1084 外观数列
 * 2023/01/02
 * */

#include <iostream>

using namespace std;

int main()
{
    int d, N;
    cin >> d >> N;
    string ans;
    ans += char(d + '0');
    int i, j, k;
    for (i = 1; i < N; ++i)
    {
        string temp;
        for (j = 0; j < ans.size();)
        {
            for (k = j; k < ans.size() && ans[k] == ans[j]; ++k);/* 记录有多少连续且和第j位一样的字符 */
            temp += ans[j] + to_string(k - j);
            j = k;/* 直接跳转 */
        }
        ans = temp;
    }
    cout << ans << endl;
}
