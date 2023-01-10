/// \name PTA 1097 矩阵行平移
/// \time 2023/01/10
/// \other 本以为这道题很难的, 没想到如此的简单

#include <iostream>

using namespace std;

const int N = 105;

/* 将变化后的矩阵打印出来, 用于debug, 二维数组传参确实有些麻烦 */
void Print(const int* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", *(matrix + i * N + j));
        printf("\n");
    }
}

int main() {
    setbuf(stdout, NULL);
    int n, k, x;
    cin >> n >> k >> x;
    int matrix[N][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]); /* 这里使用 sacnf 输入, 因为我怀疑可能有大量数据是输入和输出 */
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = n - 1; j >= 0; j--)
                if (j + cnt < N)
                    matrix[i][j + cnt] = matrix[i][j];
            for (int j = 0; j < cnt; j++)
                matrix[i][j] = x;
            cnt++;
            if (cnt == k + 1)
                cnt = 1;
        }
    }
    int sum;
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += matrix[i][j];
        printf("%d", sum);
        if (j != n - 1)
            printf(" ");
    }
}
