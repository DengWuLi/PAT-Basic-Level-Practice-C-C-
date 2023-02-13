/// PAT (Basic  Level) Practice
/// 1111 对称日  15/15
/// 2023-02-13

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;


bool Judge(string& str) {
    string temp = str;
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != temp[i])
            return false;
    return true;
}

int main() {
    map<string, string> mon = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

    int N;
    cin >> N;
    string Month, temp;
    string day, year;
    Month.resize(3);
    int Day, Year;
    int size;
    for (int i = 0; i < N; i++) {

        scanf("%s %d, %d\n", &Month[0], &Day, &Year);

        year = to_string(Year);
        size = year.size();
        for (int j = 0; j < 4 - size; j++)
            year = "0" + year;

        day = to_string(Day);
        size = day.size();
        for (int j = 0; j < 2 - size; j++)
            day = "0" + day;

        temp = year + mon.at(Month) + day;

        if (Judge(temp))
            cout << "Y ";
        else
            cout << "N ";
        cout << temp << endl;
    }
}
