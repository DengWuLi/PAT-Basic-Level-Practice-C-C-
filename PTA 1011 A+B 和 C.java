/// PTA 1011 A+B 和 C
/// 2023/01/06

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        long a, b, c;
        for (int i = 0; i < t; i++) {
            a = input.nextInt();
            b = input.nextInt();
            c = input.nextInt();
            if (a + b > c)
                System.out.printf("Case #%d: true\n", i + 1);
            else
                System.out.printf("Case #%d: false\n", i + 1);
        }
    }
}
