/// PTA 1009 说反话
/// 2023/01/06

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] ans = str.split(" ");
        for (int i = ans.length - 1; i >= 0; i--) {
            System.out.print(ans[i]);
            if (i != 0)
                System.out.print(" ");
        }
    }
}
