/// \name PTA 1055 集体照
/// \time 2023/01/09
/// \other 抄的大佬的代码

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    string name;
    int height;
};

int cmp(const struct node& a, const struct node& b) { return a.height != b.height ? a.height > b.height : a.name < b.name; }

int main() {
    int n, k, m;
    cin >> n >> k;
    vector<node> stu(n);
    for (int i = 0; i < n; i++)
        cin >> stu[i].name >> stu[i].height;

    sort(stu.begin(), stu.end(), cmp);
    int t = 0, row = k;
    while (row) {
        if (row == k) /* 如果是第最后一行, 注意应该先输出最后一行, 最后一行能站的人数 */
            m = n - n / k * (k - 1);
        else
            m = n / k;
        vector<string> ans(m);
        ans[m / 2] = stu[t].name;
        
        /* 最高者左侧 */
        int j = m / 2 - 1;
        for (int i = t + 1; i < t + m; i = i + 2)
            ans[j--] = stu[i].name;
        
        /* 最高者右侧 */
        j = m / 2 + 1;
        for (int i = t + 2; i < t + m; i = i + 2)
            ans[j++] = stu[i].name;
        
        /* 输出当前排 */
        cout << ans[0];
        for (int i = 1; i < m; i++)
            cout << " " << ans[i];
        cout << endl;
        t = t + m;
        row--;
    }
    return 0;
}
