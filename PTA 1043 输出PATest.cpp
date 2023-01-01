/* 1043 输出PATest
 * 2022/08/14
 * */

#include <iostream>

using namespace std;
int a[128] = {0};
char ch[] = {'P', 'A', 'T', 'e', 's', 't'};

bool Judge()
{
    for (char i: ch)
        if (a[i] != 0)
            return false;
    return true;
}

int main()
{
    string str;
    cin >> str;

    for (char i: str)
        a[i]++;
    while (!Judge())
    {
        for (char i : ch)
            if (a[i] != 0)
            {
                a[i]--;
                cout << i;
            }
    }
}
