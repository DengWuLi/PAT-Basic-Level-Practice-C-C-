/// \name PTA 1095 解码PAT准考证
/// \time 2023/01/09
/// \other 没有几乎将所有的cin与cout转化为scanf和printf就能通过全部测试点, 真是太有意思了.


#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Student {
    string str;
    int number{};
    string date;
    int score{};
};

struct Number {
    int number{};
    int cnt{0};
};

bool Cmp(const Student& a, const Student& b) { return a.score != b.score ? a.score > b.score : a.str < b.str; }

bool Cmp1(const Student& a, const Student& b) { return a.score != b.score ? a.score > b.score : a.number < b.number; }


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    // cin >> N >> M;
    Student stu[N + 1];
    // vector<Student> stu(N);
    string temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        scanf("%d", &stu[i].score);
        stu[i].str = temp;
        stu[i].number = stoi(temp.substr(1, 3)); /* 考场编号 */
        stu[i].date = temp.substr(4, 6);         /* 考试日期 */
    }

    int type;
    string order;
    sort(stu, stu + N, Cmp);
    // sort(stu.begin(), stu.end(), Cmp);

    for (int i = 1; i <= M; i++) {
        cin >> type >> order;
        // cout << "Case " << i << ": " << type << " " << order << endl;
        printf("Case %d: %d %s\n", i, type, order.c_str());

        if (type == 1) {
            bool flag = false;
            for (auto& j : stu)
                if (j.str[0] == order[0]) {
                    printf("%s %d\n", j.str.c_str(), j.score);
                    // cout << j.str << ' ' << j.score << endl;
                    flag = true;
                }
            if (!flag)
                printf("NA\n");
            // cout << "NA" << endl;
        }
        else if (type == 2) {
            int count = 0, sum = 0;
            int number = stoi(order);
            for (int j = 0; j < N; j++)
                if (stu[j].number == number) {
                    count++;
                    sum += stu[j].score;
                }
            if (count != 0)
                printf("%d %d", count, sum);
            // cout << count << ' ' << sum;
            else
                printf("NA");
            // cout << "NA";
            printf("\n");
            // cout << endl;
        }
        else if (type == 3) {
            vector<Student> ans;
            unordered_map<int, int> m;
            for (auto& item : stu)
                if (item.date == order)
                    m[item.number]++;
            for (auto& item : m) {
                /* 此处的temp只是用于输出, 其中number存储着考场, score存储着对应考场的学生个数, 相当于变量复用了.
                 * 这个复用思想挺值得学习的.
                 * */
                Student tempStu;
                tempStu.number = item.first;
                tempStu.score = item.second;
                ans.push_back(tempStu);
            }
            sort(ans.begin(), ans.end(), Cmp1);
            if (ans.empty())
                printf("NA\n");
            // cout << "NA" << endl;
            else {
                for (auto& item : ans)
                    printf("%d %d\n", item.number, item.score);
                // cout << an.number << " " << an.score << endl;
            }
        }
    }
}
