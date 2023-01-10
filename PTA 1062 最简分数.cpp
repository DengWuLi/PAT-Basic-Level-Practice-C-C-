/// \name PTA 1062 最简分数
/// \time 2023/01/10
/// \other 这个题单从题目描述来说挺难理解的, 还是看了解析才明白的, 还有就是这个浮点数的精度问题


#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    if (n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }

    vector<int> ans;

    for (int i = 1; i < k; i++) {
        if ((i * m1 > n1 * k) && (i * m2 < n2 * k))
            if (gcd(i, k) == 1)
                ans.push_back(i);
    }
    int size = ans.size();
    for (int i = 0; i < size; i++) {
        printf("%d/%d", ans[i], k);
        if (i != size - 1)
            printf(" ");
    }
}
