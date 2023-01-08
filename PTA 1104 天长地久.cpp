/// \name PTA 1104 天长地久 \n
/// \time 2023/01/08 \n
/// \other 参考了B站大佬代码 \n

#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

unordered_set<int> h;
int flag;
set<pair<int, int>> ans;

int GCG(int m, int n) { return !n ? m : GCG(n, m % n); }

bool isPrime(int x) {
    if (x <= 1) return false;
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
        if (x % i == 0) return false;
    return true;
}

/// \param current &emsp 当前搜索到的位数
/// \param K &emsp 总共的位数
/// \param m &emsp A的各位之和
/// \param sum &emsp 前面各位之和
/// \param A &emsp 最后的答案

void DFS(int current, int K, int m, int sum, int A) {
    /* 递归出口*/
    if (current > K)
        return;
    /* 进行DFS的剪枝, 如果不进行剪枝, 最后一个测试点会超时 */
    /* 如何剪枝: 假设随后几位均为最大值9, 此种情况下, sum依然小于m, 则直接返回 */
    if (sum + (K - current) * 9 < m) return;

    if (current == K) {
        if (sum == m) {
            int B = A + 1;
            int n = 0;
            /* 计算B各位之和 */
            do {
                n += B % 10;
                B /= 10;
            } while (B);
            /* 如果n在之前计算的集合中, 就将对应的n和A插入到一个集合中 */
            if (h.count(n)) {
                flag = true;
                ans.insert({n, A});
            }
        }
        else
            return;
    }
    else {
        for (int i = 0; i <= 9; i++) {
            ///  \attention <p,color = "red"> 首位不能取0! </p>
            if (current == 0 && i == 0) continue;
            DFS(current + 1, K, m, sum + i, A * 10 + i);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << "Case " << i << endl;
        int K, m;
        cin >> K >> m;
        flag = false;
        /* 这两个全局变量要注意每次循环的时候清空 */
        h.clear();
        ans.clear();
        /* 预处理m, n, 即找到m和n的最大公约数是一个大于2的素数, 并将其存放在哈希表中. */
        for (int n = 1; n <= 90; n++) {
            auto temp = GCG(n, m);
            if (temp > 2 && isPrime(temp))
                h.insert(n); /* 可能的n存放在h中 */
        }
        /* DFS 深度搜索 */
        DFS(0, K, m, 0, 0);
        if (!flag)
            cout << "No Solution\n";
        else
            for (const auto& x : ans)
                printf("%d %d\n", x.first, x.second);
    }
}
