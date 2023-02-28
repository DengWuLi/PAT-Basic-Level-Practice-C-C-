/// PAT (Basic Level) Practice
/// 1013 数素数 20/20
/// 2023-02-28
/// 在毛概课上写题

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] argc) {
        var input = new Scanner(System.in);
        var m = input.nextInt();
        var n = input.nextInt();
        List<Integer> prime = new ArrayList<>();
        var count = 0;

        for (int i = 2; count < n; i++)
            if (isPrime(i)) {
                count++;
                if (count >= m)
                    prime.add(i);
            }

        count = 0;
        for (Integer integer : prime) {
            count += 1;
            if (count % 10 != 1)
                System.out.print(" ");
            System.out.print(integer);
            if (count % 10 == 0)
                System.out.println();
        }
    }

    public static boolean isPrime(int n) {
        if (n == 1)
            return false;
        else if (n == 2)
            return true;

        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;

        return true;
    }
}
