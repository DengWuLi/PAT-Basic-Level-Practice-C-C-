/// PAT (Basic  Level) Practice
/// 1112 超标区间  20/20
/// 2023-02-12
/// 不可思议, 这个题目集竟然是更新的.


#include <iostream>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    int left = 0, right = 0, maxNum = -1;
    int temp, flag = false;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        maxNum = max(maxNum, temp);
        if (temp > T && flag)
            right = i;
        else if (temp > T && !flag) {
            left = right = i;
            flag = true;
        }
        else if (temp <= T && flag) {   // 注意是 "<="!
            cout << "[" << left << ", " << right << "]" << endl;
            flag = false;
            maxNum = 1001;
        }
    }

    // 如果循环结束, 还在计数区间内, 也要输出的, 这一点比较难想到
    if (flag) {
        cout << "[" << left << ", " << right << "]" << endl;
        return 0;
    }

    if (maxNum < 1001)
        cout << maxNum;
}
