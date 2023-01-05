/// PTA 1001 害死人不偿命的(3n+1)猜想
/// 2023/01/05

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner myscan = new Scanner(System.in);
        int n = myscan.nextInt();
        int count = 0;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3 * n + 1) / 2;
            count++;
        }
        System.out.println(count);
    }
}
