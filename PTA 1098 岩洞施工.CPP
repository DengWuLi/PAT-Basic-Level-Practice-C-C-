#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int MAX = -1, MIN = INT_MAX;
    int temp;
    /* ---- 先找上面最小的, 再找下面最大的 ---- */
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        MIN = min(MIN, temp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        MAX = max(MAX, temp);
    }
    if (MIN - MAX > 0)
        printf("Yes %d\n", MIN - MAX);
    else
        printf("No %d\n", MAX - MIN + 1);
}
