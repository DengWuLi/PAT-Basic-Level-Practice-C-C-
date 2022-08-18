/* PTA 1082 射击比赛
 * 2022/08/18
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Athlete
{
    string ID;
    double x, y;
    double distance{0};
};

bool Pred(Athlete a, Athlete b)
{
    return a.distance < b.distance;
}

int main()
{
    int N;
    cin >> N;
    vector<Athlete> ath(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ath[i].ID >> ath[i].x >> ath[i].y;
        ath[i].distance = ath[i].x * ath[i].x + ath[i].y * ath[i].y;
    }
    sort(ath.begin(), ath.end(), Pred);
    cout << ath[0].ID << " " << ath[N - 1].ID;
}