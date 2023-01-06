/// PTA 1005 继续(3n+1)猜想
/// 2023/01/06

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        /* 要想使用Java中sort函数实现降序排列, 竟然要使用其对应的类, 比C++麻烦不少 */
        Integer[] p = new Integer[n];
        for (int i = 0; i < n; i++)
            p[i] = input.nextInt();
        for (int i = 0; i < n; i++) {
            if (p[i] != 0) {
                for (int j = p[i]; j != 1; ) {
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
        Arrays.sort(p, Collections.reverseOrder());
        int m = 0;
        for (; m < n; m++)
            if (p[m] == 0)
                break;
        for (int i = 0; i < m; i++) {
            System.out.print(p[i]);
            if (i != m - 1)
                System.out.print(" ");
        }

    }
}
