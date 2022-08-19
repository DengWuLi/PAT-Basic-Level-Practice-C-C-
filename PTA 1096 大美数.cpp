/* PTA 1096 大美数
 * 2022/08/18
 * */

#include <iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;
    int num;
    for (int i = 0; i < K; i++)
    {
        bool flag = false;
        cin >> num;
        for (int a = 1; a < num; a++)
        {
            if (flag)
                break;
            if (num % a != 0)
                continue;
            for (int b = a + 1; b < num; b++)
            {
                if (flag)
                    break;
                if (num % b != 0)
                    continue;
                for (int c = b + 1; c < num; c++)
                {
                    if (flag)
                        break;
                    if (num % c != 0)
                        continue;
                    for (int d = c + 1; d <= num; d++)  //注意此处有一个等号.
                    {
                        if (num % d != 0)
                            continue;
                        if ((a + b + c + d) % num == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
            }

        }
        if (flag)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }

}
