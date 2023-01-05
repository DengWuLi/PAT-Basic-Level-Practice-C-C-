/// PTA 1002 写出这个数
/// 2023/01/05

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int sum = 0;
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        for (int i = 0; i < str.length(); i++)
            sum += str.charAt(i) - '0';

        str = String.valueOf(sum);
        for (int i = 0; i < str.length(); i++) {
            switch (str.charAt(i)) {
                case '0':
                    System.out.print("ling");
                    break;
                case '1':
                    System.out.print("yi");
                    break;
                case '2':
                    System.out.print("er");
                    break;
                case '3':
                    System.out.print("san");
                    break;
                case '4':
                    System.out.print("si");
                    break;
                case '5':
                    System.out.print("wu");
                    break;
                case '6':
                    System.out.print("liu");
                    break;
                case '7':
                    System.out.print("qi");
                    break;
                case '8':
                    System.out.print("ba");
                    break;
                case '9':
                    System.out.print("jiu");
                    break;
                default:
                    continue;
            }
            if (i < str.length() - 1)
                System.out.print(" ");
        }

    }
}
