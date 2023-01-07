/// PTA 1021 个位数统计
/// 2023/01/07

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        int length = str.length();
        int[] cnt = new int[10];
        int i;
        for (i = 0; i < length; i++)
            cnt[str.charAt(i) - '0']++;
        for (i = 0; i < 10; i++)
            if (cnt[i] != 0)
                System.out.printf("%d:%d\n", i, cnt[i]);
    }
}
