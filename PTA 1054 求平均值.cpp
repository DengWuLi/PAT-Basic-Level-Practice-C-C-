/* PTA 1054 求平均值
 * 2022/01/02
 * */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char string1[50], string2[50];
    double m;
    int i, cnt = 0, flag = 1;
    double sum = 0;
    while (N--)
    {
        flag = 1;
        cin >> string1;/* 先将输入当作字符串读入 */
        sscanf(string1, "%lf", &m);/* 之后再将输入按照浮点数读入 */
        sprintf(string2, "%.2lf", m);/* 再将浮点数按照规定格式转化为字符串 */
        for (i = 0; i < strlen(string1); i++)/* 通过循环看看两个数是否相等 */
            if (string1[i] != string2[i])
            {
                flag = 0;/* 如果不相等, 说明输入不正确 */
                break;
            }
        if (flag == 0 || m > 1000 || m < -1000)
        {
            printf("ERROR: %s is not a legal number\n", string1);
            continue;
        }
        else
        {
            sum += m;
            cnt++;
        }
    }
    if (cnt > 1) printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    else if (cnt == 1) printf("The average of 1 number is %.2f\n", sum / cnt);/* 注意这里要对 1 这种情况进行单独判断*/
    else printf("The average of 0 numbers is Undefined\n");
}
