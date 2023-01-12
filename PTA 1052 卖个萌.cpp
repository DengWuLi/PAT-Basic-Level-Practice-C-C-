/// PTA 1052 卖个萌
/// 2023/01/12
/// 本人使用 WSL 和 VScode 打的第一个程序, 虽然也是照着教程打的, 但也是值得记录的.

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    vector<vector<string>> v;
    string str;
    int j = 0, k = 0;
    for (int i = 0; i < 3; i++) {

        // 输入字符串
        getline(cin, str);

        vector<string> r;
        j = 0, k = 0;
        while (j < str.length()) {
            if (str[j] == '[') {
                while (k++ < str.length()) {
                    if (str[k] == ']') {
                        r.push_back(str.substr(j + 1, k - j - 1));
                        break;
                    }
                }
            }
            j++;
        }
        v.push_back(r);
    }
    int n;
    cin >> n;
    // 左手 (左眼 口 右眼) 右手
    int a, b, c, d, e;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d >> e;
        if (a > v[0].size() || b > v[1].size() || c > v[2].size()
            || d > v[1].size() || e > v[0].size()
            || a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {
            cout << "Are you kidding me? @\\/@\n";
            continue;
        }
        else {
            cout << v[0][a - 1]
                 << "("
                 << v[1][b - 1] << v[2][c - 1] << v[1][d - 1]
                 << ")"
                 << v[0][e - 1] << endl;
        }
    }
}
