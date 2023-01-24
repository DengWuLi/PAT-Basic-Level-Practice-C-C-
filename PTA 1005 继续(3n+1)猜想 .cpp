#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++) {
        if (p[i] == 0)
            continue;
        else {
            for (int j = p[i]; j != 1;) {
                if (j % 2 == 0)
                    j /= 2;
                else
                    j = (3 * j + 1) / 2;
                for (int k = 0; k < n; k++)
                    if (p[k] == j)
                        p[k] = 0;
            }
        }
    }
    sort(p, p + n, greater<>());
    int m = 0;
    for (; m < n; m++)
        if (p[m] == 0)
            break;

    for (int i = 0; i < m; i++) {
        cout << p[i];
        if (i != m - 1)
            cout << " ";
    }
}
