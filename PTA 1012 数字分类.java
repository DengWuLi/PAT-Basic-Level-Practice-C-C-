/// PTA 1012 数字分类
/// 2023/01/06

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[5];
        int j = 0, count = 0, temp;
        while (n-- > 0) {
            temp = input.nextInt();
            switch (temp % 5) {
                case 0:
                    if (temp % 2 == 0)
                        a[0] += temp;
                    break;
                case 1:
                    if (j % 2 == 0)
                        a[1] = a[1] + temp;
                    else
                        a[1] = a[1] - temp;
                    j++;
                    break;
                case 2:
                    a[2]++;
                    break;
                case 3:
                    a[3] += temp;
                    count++;
                    break;
                case 4:
                    a[4] = Math.max(a[4], temp);
                    break;
                default:
                    break;
            }
        }
        double ave = 0;
        if (count != 0)
            ave = a[3] * 1.0 / count;
        for (int i = 0; i < 5; i++) {
            switch (i) {
                case 1:
                    if (j != 0)
                        System.out.print(a[i]);
                    else
                        System.out.print("N");
                    break;
                case 3:
                    if (a[i] == 0)
                        System.out.print("N");
                    else
                        System.out.printf("%.1f", ave);
                    break;
                default:
                    if (a[i] == 0)
                        System.out.print("N");
                    else
                        System.out.print(a[i]);
            }
            if (i != 4)
                System.out.print(" ");
        }
    }
}
