/// PTA 1050 螺旋矩阵
/// 2023/01/12
/// 大佬的思路就是厉害啊, 有必要跟随大佬的思路打题

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N + 1];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int m, n;
    // 计算m和n
    for (n = sqrt(N); n >= 1; n--)
        if (N % n == 0) {
            m = N / n;
            break;
        }
    sort(arr, arr + N, greater<int>());
    vector<vector<int>> ans(m, vector<int>(n));

    // 先对矩阵进行初始化
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = -1;

    // 行走方向
    int dirX[] = {-1, 0, 1, 0},
        dirY[] = {0, 1, 0, -1};

    int x = 0, y = 0, dir = 1;
    int nextX, nextY;
    for (int i = 0; i < N; i++) {
        ans[x][y] = arr[i];
        nextX = x + dirX[dir], nextY = y + dirY[dir];
        // 表示应该转向了
        if ((nextX < 0 || nextX >= m) || (nextY < 0 || nextY >= n) || ans[nextX][nextY] != -1) {
            dir = (dir + 1) % 4;
            nextX = x + dirX[dir], nextY = y + dirY[dir];
        }
        x = nextX, y = nextY;
    }
    // 输出
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j != n - 1)
                cout << ' ';
        }
        cout << "\n";
    }
}
