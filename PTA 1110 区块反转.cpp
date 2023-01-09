/// \name PTA 1110 区块反转
/// \time 2023/01/09
/// \other 仿照B站大佬的思路写的, 属于是举一反三了

#include <iostream>
#include <vector>

using namespace std;

const int N = 1E5 + 10;
struct Node {
    int address, data, next, pre;
} node[N];

void Print(int head, int n, int K) {
    int count = 0;
    auto p = head;

    vector<Node> ans[n / K + 1];
    int j = 0;
    while (p != -1) {

        ans[j].push_back(node[p]);
        p = node[p].next;
        count++;
        if (count % K == 0)
            j++;
    }

    for (int i = j; i >= 0; i--) {
        int size = ans[i].size();
        for (int k = 0; k < size; k++) {
            printf("%05d %d ", ans[i][k].address, ans[i][k].data);
            if (k == size - 1 && i == 0)
                printf("-1");
            else if (k == size - 1)
                printf("%05d\n", ans[i - 1][0].address);
            else
                printf("%05d\n", ans[i][k + 1].address);
        }
    }
}

int main() {
    int L1, n, K;
    cin >> L1 >> n >> K;
    int address, data, next;
    for (int i = 0; i < n; i++) {
        cin >> address >> data >> next;
        node[address] = {address, data, next};
    }
    Print(L1, n, K);
}
