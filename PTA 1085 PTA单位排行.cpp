/// \name PTA 1085 PTA单位排行
/// \time 2022/08/19
/// \other 测试点5有小坑, 已经在相关函数中说明了, <a href="http://t.csdn.cn/DAn2P"> 参考这篇博文 </a>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct School {
    string name;
    double score{0.0};
    int cnt{0};
};

bool Pred(const School& a, const School& b) {

    /** \修改 测试点5的坑, 注意要将原本score的double转化为int类型后在进行比较 */
    int aScore = static_cast<int>(a.score),
        bScore = static_cast<int>(b.score);

    if (aScore != bScore)
        return aScore > bScore;
    else if (a.cnt != b.cnt)
        return a.cnt < b.cnt;
    else
        return a.name < b.name;
}

int main() {
    int N;
    cin >> N;
    map<string, School> sch;
    for (int i = 0; i < N; i++) {
        string ID, name;
        double score;
        cin >> ID >> score >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        sch[name].cnt++;
        if (ID[0] == 'B')
            sch[name].score += score / 1.5;
        else if (ID[0] == 'A')
            sch[name].score += score;
        else if (ID[0] == 'T')
            sch[name].score += score * 1.5;
    }
    vector<School> s;
    for (auto& i : sch)
        s.push_back({i.first, i.second.score, i.second.cnt});   // 将数据存入结构体, 头一次接触这种写法
    sort(s.begin(), s.end(), Pred);
    cout << s.size() << "\n";

    int j = 1, cnt = 0;
    int score = int(s[0].score);
    for (auto& i : s) {
        cnt++;
        if (score != int(i.score))
            j = cnt;
        printf("%d %s %d %d\n", j, i.name.c_str(), int(i.score), i.cnt);
        score = int(i.score);
    }
}
