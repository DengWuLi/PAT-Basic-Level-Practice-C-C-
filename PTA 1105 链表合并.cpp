/// \name PTA 1105 链表合并
/// \time 2023/01/09
/// \other 还是B站大佬牛
#include <iostream>
#include <vector>

using namespace std;

const int N = 1E5 + 10;
struct Node {
    int address, data, next, pre;
} node[N];

void Print(int head, int tail) {
    int count = 0;
    auto p = head, q = tail;
    vector<Node> ans;
    while (p != -1) {
        ans.push_back(node[p]);
        p = node[p].next;
        count++;
        if (count % 2 == 0 && q != -1) {
            ans.push_back(node[q]);
            q = node[q].pre;
        }
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

int main() {
    int L1, L2, n;
    cin >> L1 >> L2 >> n;
    int address, data, next;
    for (int i = 0; i < n; i++) {
        cin >> address >> data >> next;
        node[address] = {address, data, next};
    }
    // 遍历静态链表, 使原本的单向链表变为双向链表
    auto p = L1;
    auto pre = -1;
    int len1 = 0;
    while (p != -1) {
        len1++;
        node[p].pre = pre;
        pre = p;
        p = node[p].next;
    }

    auto q = L2;
    auto pre2 = -1;
    int len2 = 0;
    while (q != -1) {
        len2++;
        node[q].pre = pre2;
        pre2 = q;
        q = node[q].next;
    }

    if (len1 > len2)
        Print(L1, pre2);
    else
        Print(L2, pre);
}
