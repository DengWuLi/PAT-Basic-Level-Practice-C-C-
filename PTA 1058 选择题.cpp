/// PTA 1058 选择题
/// 2023/01/14
/// 第一次使用lambda表达式写sort函数, 感觉比在main函数之外单独命名一个函数要方便和好看.
/// 同时C++中pair的用法真是太方便了.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Problems {
    int score;
    int allCount;
    int ansCount;
    char answers[6];
};

int main() {
    int N, M;
    cin >> N >> M;
    Problems pro[M + 1];
    int i, j;
    for (i = 0; i < M; i++) {
        cin >> pro[i].score >> pro[i].allCount >> pro[i].ansCount;
        // 首先把存储答案的区域全部初始化为'\0', 注意: sizeof(数组)返回的是整个数组的大小
        // 除了a被用作运算符sizeof的参数这一情形, 在其他所有的情形中数组名a都代表指向数组a中下标为0的元素的指针
        memset(pro[i].answers, '\0', sizeof(pro[i].answers));
        for (j = 0; j < pro[i].ansCount; j++)
            cin >> pro[i].answers[j];
    }
    // 存储错误最多的题目的编号和错误次数, 此处使用lambda表达式进行排序
    vector<pair<int, int>> wrong;
    for (i = 0; i < M; i++)
        wrong.emplace_back(i + 1, 0);
    auto f = [](pair<int, int> a, pair<int, int> b) { return a.second == b.second ? a.first < b.first : a.second > b.second; };

    // 输入的字符
    char ch;
    // 学生答案的个数
    int stuAnsCount;
    // 学生的答案
    char stuAns[6];
    // 学生的分数, 以及一个下标(用于统计错误题目)
    int index, score;

    // 吸收一个换行符
    getchar();
    for (i = 0; i < N; i++) {
        index = 0, score = 0;

        while ((ch = getchar()) && ch != '\n') {

            if (ch == '(') {
                cin >> stuAnsCount;
                // 首先把存储答案的区域全部初始化为'\0'
                memset(stuAns, '\0', sizeof(stuAns));
                for (j = 0; j < stuAnsCount; j++)
                    cin >> stuAns[j];

                if (strcmp(stuAns, pro[index].answers) == 0)
                    score += pro[index].score;
                else
                    wrong[index].second++;
                index++;
            }
        }
        cout << score << endl;
    }

    sort(wrong.begin(), wrong.end(), f);
    int maxWrongTimes = wrong[0].second;
    if (maxWrongTimes == 0)
        cout << "Too simple";
    else {
        // 先输出错误次数
        cout << maxWrongTimes;
        // 再依次输出编号
        for (i = 0; i < wrong.size(); i++)
            if (wrong[i].second == maxWrongTimes)
                cout << " " << wrong[i].first;
            else
                break;
    }
}
