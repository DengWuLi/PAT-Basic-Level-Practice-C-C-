/// PAT (Basic Level) Practice (中文)
/// 1003 我要通过!
/// 2023-01-17

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String str;
        for (int i = 0; i < n; i++) {
            str = in.next();
            if (judge(str))
                System.out.println("YES");
            else
                System.out.println("NO");

        }
    }

    public static boolean judge(String str) {
        int PNum = 0, TNum = 0;

        int[] ANum = {0, 0, 0};

        for (int i = 0; i < str.length(); i++) {

            if (str.charAt(i) != 'P' && str.charAt(i) != 'A' && str.charAt(i) != 'T')
                return false;

            if (str.charAt(i) == 'P') {
                PNum++;
                if (PNum > 1 || TNum != 0)
                    return false;
            } else if (str.charAt(i) == 'T') {
                TNum++;
                if (TNum > 1 || PNum == 0)
                    return false;
            } else {
                if (PNum == 0 && TNum == 0)
                    ANum[0]++;
                else if (PNum != 0 && TNum == 0)
                    ANum[1]++;
                else
                    ANum[2]++;
            }
        }

        if (PNum == 0 || TNum == 0 || ANum[1] == 0 || (ANum[0] * ANum[1] != ANum[2]))
            return false;
        else
            return true;
    }
}
