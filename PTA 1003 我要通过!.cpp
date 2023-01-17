/// PTA 1003 我要通过!
/// 首次写于: 2022-07-17, 修改与 2023-01-17
/// m没想到竟然都在去年7月和今年1月碰到这个题, 真可以说是缘分的呢.
/// 之前太注意通过了, 代码没怎么写注释, 今天回来不上, ☺

#include <iostream>

using namespace std;

bool judge(string s) {
    // 这两个变量分别用来记录字符串中P, T出现的次数
    int PNum = 0, TNum = 0;

    /**
     * 用来统计A出现的次数, 根据题意可以将A出现的位置划分为三中情况:
     * <ol>
     * <li>出现在P的左边, 用<strong>ANum[0]</strong>表示</li>
     * <li>出现在P和T的中间, 用<strong>ANum[1]</strong>表示</li>
     * <li>出现在T的右边, 用<strong>ANum[3]</strong>表示</li>
     * </ol>
     * 统计到最后只要判断一下:
     * <p>ANum[0]*ANum[1]?=ANum[3]</p>即可
     * */

    int ANum[3] = {0};
    int a[5] = {0};
    for (char i : s) {
        // 当一个字符串中出现了非`P`, `A`, `T`这三种字符时, 直接返回false
        if (i != 'P' && i != 'A' && i != 'T')
            return false;
        // 当检测到字符=='P'时, PNum++, 同时进行判断, 若字符串中P出现的次数>1 || 在P出现之前, T已经出现, 直接返回false
        if (i == 'P') {
            PNum++;
            if (PNum > 1 || TNum != 0)
                return false;
        }
        // 当检测到字符=='T'时, TNum++, 同时进行判断, 若字符串中T出现的次数>1 || 在T出现后, P仍未出现, 直接返回false.
        else if (i == 'T') {
            TNum++;
            if (TNum > 1 || PNum == 0)
                return false;
        }
        else {
            if (PNum == 0 && TNum == 0)
                ANum[0]++;
            else if (PNum != 0 && TNum == 0)
                ANum[1]++;
            else
                ANum[2]++;
        }
    }
    // "PAAAAA" 这样的代码也是不能通过的
    if (PNum == 0 || TNum == 0 || ANum[1] == 0)
        return false;

    if(ANum[0]*ANum[1]!=ANum[2])
        return false;
    else
        return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (judge(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
