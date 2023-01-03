/* PTA 1025 反转链表
 * 2023/01/03
 * */

#include <iostream>
#include <vector>

using namespace std;
/* 此结构体node用于存储与反转 */
struct Node
{
    int data, next;
};
/* 此结构体node用于输出*/
struct node
{
    int pre, data;
};

int main()
{
    int start;
    int N, K;
    cin >> start >> N >> K;
    Node List[100005];
    int Address, Data, Next;
    for (int i = 0; i < N; i++)
    {
        cin >> Address >> Data >> Next;
        List[Address].data = Data;
        List[Address].next = Next;
    }

    vector<node> temp, result;
    for (int i = start; i != -1; i = List[i].next)
    {
        temp.push_back({ i, List[i].data });
        /* 反转压入, 注意压入时记录头*/
        if (temp.size() == K)
        {
            while (!temp.empty())
            {
                result.push_back(temp.back());
                temp.pop_back();
            }
        }
    }
    /* 多余的不用反转 */
    while (!temp.empty())
    {
        result.push_back(temp.front());
        temp.erase(temp.begin());
    }

    /* 输出 */
    for (int i = 0; i < result.size() - 1; i++)
    {
        printf("%05d %d %05d\n", result[i].pre, result[i].data, result[i + 1].pre);
    }
    printf("%05d %d -1", result.back().pre, result.back().data);
}
