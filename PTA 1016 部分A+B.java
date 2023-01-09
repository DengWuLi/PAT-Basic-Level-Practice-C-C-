/// PTA 1016 部分A+B
/// 2023/01/09

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String A, Da, B, Db;
        A = input.next();
        Da = input.next();
        B = input.next();
        Db = input.next();

        System.out.printf("%d\n", fun(A, Da) + fun(B, Db));
    }

    static int fun(String A, String Da) {
        int count = 0;
        for (int i = 0; i < A.length(); i++)
            if (A.charAt(i) == Da.charAt(0))
                count++;

        int Pa = 0;
        for (int i = 0; i < count; i++)
            Pa = Pa * 10 + Da.charAt(0) - '0';
        return Pa;
    }
}
