/// 1010 一元多项式求导
/// 2023/01/06

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a, b;
        a = input.nextInt();
        b = input.nextInt();
        if (b == 0) {
            System.out.print("0 0");
            return;
        } else
            System.out.printf("%d %d", a * b, b - 1);
        while (input.hasNextInt()) {
            a = input.nextInt();
            b = input.nextInt();
            if (b != 0)
                System.out.printf(" %d %d", a * b, b - 1);
        }

    }
}
