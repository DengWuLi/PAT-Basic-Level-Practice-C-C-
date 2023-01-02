/* PTA 1091 N-自守数
 * 2023/01/02
 * */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int M;
    cin >> M;
    int K, cnt, temp, i,a;
    while (M--)
    {
        cin >> K;
        temp = K, cnt = 1;
        while ((temp /= 10) != 0)
            cnt++;
        temp = K * K;
        for (i = 0; i < 10; i++)
        {
            a = i * temp % int(pow(10,cnt));
            if (a == K)
            {
                cout << i << ' ' << i * temp << endl;
                break;
            }
        }
        if (i == 10)
            cout << "No\n";
    }
}
