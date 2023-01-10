/// \name PTA 1089 狼人杀-简单版
/// \time 2023/01/10
/// 没想到竟然有非零返回这种骚错误

#include <iostream>

using namespace std;

int arr[105];
int wolf[105] = {0};
int N;

bool Judge(int x, int y) {
    int lie[105] = {0};
    int lieNum = 0;
    for (int i = 1; i <= N; i++) {
        /* 如果一个人说某个人为狼人, 但是在循环假设中这个人不是狼人, 说明这个人说谎 */
        if (arr[i] < 0 && wolf[-arr[i]] != 1) {
            lie[i] = 1;
            lieNum++;
        }
        /* 如果一个人说某个人不是狼人, 但是在循环假设中这个人是狼人, 说明这个人说谎 */
        else if (arr[i] > 0 && wolf[arr[i]] == 1) {
            lie[i] = 1;
            lieNum++;
        }
    }
    if (lieNum > 2 || lie[x] + lie[y] != 1)
        return false;
    else {
        cout << x << " " << y << endl;
        return true;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i]; /* 把每个人的猜测写进数组中 */

    for (int i = 1; i <= N; i++) {
        wolf[i] = 1; /* 假设i为狼人 */
        for (int j = i + 1; j <= N; j++) {
            wolf[j] = 1;
            if (Judge(i, j))
                return 1;
            else
                wolf[j] = 0;
        }
        wolf[i] = 0;
    }
    cout << "No Solution" << endl;
}
