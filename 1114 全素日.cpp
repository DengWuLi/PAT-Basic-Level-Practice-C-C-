/// PAT (Basic  Level) Practice
/// 1114 全素日  20/20
/// 2023-02-13
/// 本以为这道题需要用到质数筛这类高级算法, 结果写一个质数的判断函数就搞定了

#include <iostream>
#include <string>
#include <valarray>

using namespace std;


bool isPrime(const int& num) {
    if (num == 0 || num == 1)
        return false;
    else if (num == 2)
        return true;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

const int N = 99991231 + 1;

int main() {

    int count = 0;
    string str, temp;
    cin >> str;

    size_t len = str.length();
    for (int i = 0; i < len; i++) {
        temp = str.substr(i, len - i);
        if (isPrime(stoi(temp))) {
            cout << temp << ' ' << "Yes" << endl;
            count++;
        }
        else
            cout << temp << ' ' << "No" << endl;
    }
    if (count == len)
        cout << "All Prime!" << endl;
}
