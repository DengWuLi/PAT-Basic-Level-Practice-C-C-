/* PTA 1100 校庆
 * 2022/01/03
 * */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(const string& a, const string& b)
{
    return a.substr(6, 8) < b.substr(6, 8);
}

int main()
{
    unordered_map<string, int> m;
    vector<string> stu, guest;/* stu存储校友, guest存储来宾*/
    int N;
    cin >> N;
    string ID;
    while (N--)
    {
        cin >> ID;
        m[ID] = 1;/* 表示校友*/
    }

    cin >> N;
    while (N--)
    {
        cin >> ID;
        if (m[ID] == 1)
            stu.push_back(ID);
        else
            guest.push_back(ID);
    }
    cout << stu.size() << endl;
    if(!stu.empty())
    {
        sort(stu.begin(), stu.end(),Comp);
        cout<<stu[0]<<endl;
    }
    else
    {
        sort(guest.begin(),guest.end(), Comp);
        cout << guest[0] << endl;
    }
}
