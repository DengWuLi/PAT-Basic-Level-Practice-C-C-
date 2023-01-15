/// PTA 1034 有理数四则运算
/// @version 2023-01-15
/// 这个逻辑条件一定要写清楚

#include <iostream>

using namespace std;

long long int GCD(long long int a, long long int b) { return b == 0 ? a : GCD(b, a % b); }

/* 把一个分数进行输出 */
void Print(long long int a, long long int b) {
    long long int temp = 0;

    if (a == 0)
        printf("0");
    else {
        bool flag = false;
        if ((a < 0 || b < 0) && !(a < 0 && b < 0)) /* 分母和分子有一个小于零, 这个逻辑条件一定要写清楚! */
            flag = true;
        if (flag)
            printf("(-");
        a = abs(a);
        b = abs(b);
        if (b == 1)
            printf("%lld", a);
        else if (a > b) {
            temp = a / b;
            a = a % b;
            printf("%lld %lld/%lld", temp, a, b);
        }
        else
            printf("%lld/%lld", a, b);

        if (flag)
            printf(")");
    }
}

void Add(long long int a, long long int b, long long int c, long long int d) {
    Print(a, b);
    printf(" + ");
    Print(c, d);
    printf(" = ");
    /* 分别计算分子和分母, 怀疑此处可能会超出long long int的限制 */
    long long int tempUp = a * d + c * b,
                  tempDown = b * d;
    long long int tempGCD = abs(GCD(tempUp, tempDown));
    // long long int tempGCD = GCD(abs(tempUp), abs(tempDown));
    tempUp /= tempGCD, tempDown /= tempGCD;
    Print(tempUp, tempDown);
    printf("\n");
}

void Subtract(long long int a, long long int b, long long int c, long long int d) {
    Print(a, b);
    printf(" - ");
    Print(c, d);
    printf(" = ");
    long long int tempUp = a * d - c * b, tempDown = b * d;
    long long int tempGCD = abs(GCD(tempUp, tempDown));
    // long long int tempGCD = GCD(abs(tempUp), abs(tempDown));
    tempUp /= tempGCD, tempDown /= tempGCD;
    Print(tempUp, tempDown);
    printf("\n");
}

void Multiply(long long int a, long long int b, long long int c, long long int d) {
    Print(a, b);
    printf(" * ");
    Print(c, d);
    printf(" = ");
    long long int tempUp = a * c, tempDown = b * d;
    long long int tempGCD = abs(GCD(tempUp, tempDown));
    // long long int tempGCD = GCD(abs(tempUp), abs(tempDown));
    tempUp /= tempGCD, tempDown /= tempGCD;
    Print(tempUp, tempDown);
    printf("\n");
}

void Divide(long long int a, long long int b, long long int c, long long int d) {
    Print(a, b);
    printf(" / ");
    Print(c, d);
    printf(" = ");


    long long int tempUp = a * d, tempDown = b * c;
    if (tempDown == 0) {
        printf("Inf");
        return;
    }
    long long int tempGCD = abs(GCD(tempUp, tempDown));
    // long long int tempGCD = GCD(abs(tempUp), abs(tempDown));
    tempUp /= tempGCD, tempDown /= tempGCD;
    Print(tempUp, tempDown);
    printf("\n");
}

int main() {
    long long int a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    //  printf("%d/%d %d/%d\n", a, b, c, d);/* 检查输入是否正确 */
    long long int temp1 = abs(GCD(a, b)), temp2 = abs(GCD(c, d));
    // long long int temp1 = GCD(abs(a), abs(b)), temp2 = GCD(abs(c), abs(d));
    a /= temp1, b /= temp1;
    c /= temp2, d /= temp2;
    Add(a, b, c, d); /* 参数传入时传入的是最简形式 */
    Subtract(a, b, c, d);
    Multiply(a, b, c, d);
    Divide(a, b, c, d);
}
