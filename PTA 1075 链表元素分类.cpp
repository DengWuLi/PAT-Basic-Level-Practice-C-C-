/// \name PTA 1075 链表元素分类
/// \time 2023/01/09

#include <iostream>
#include <vector>

using namespace std;

const int N = 1E5 + 10;
struct Node {
    int address, data, next;
} node[N];

int main() {
    int head, n, K;
    cin >> head >> n >> K;
    int address, data, next;
    for (int i = 0; i < n; i++) {
        cin >> address >> data >> next;
        node[address] = {address, data, next};
    }
    auto p = head;
    vector<Node> list;
    while (p != -1) {
        list.push_back(node[p]);
        p = node[p].next;
    }
    vector<Node> ans;
    for (auto& i : list) {
        if (i.data < 0)
            ans.push_back(i);
    }
    for (auto& i : list) {
        if (i.data >= 0 && i.data <= K)
            ans.push_back(i);
    }
    for (auto& i : list) {
        if (i.data > K)
            ans.push_back(i);
    }
    int size = ans.size();
    for (int i = 0; i < size; i++) {
        printf("%05d %d ", ans[i].address, ans[i].data);
        if (i == size - 1)
            printf("-1");
        else
            printf("%05d\n", ans[i + 1].address);
    }
}
