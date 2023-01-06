/// PTA 1022 D进制的A+B
/// 2023/01/06

import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long a = input.nextInt(), b = input.nextInt(), d = input.nextInt();
        long c = a + b;
        if (c == 0) {
            System.out.print("0");
            return;
        }
        Vector array = new Vector();
        while (c != 0) {
            array.add(c % d);
            c /= d;
        }
        for (int i = array.size() - 1; i >= 0; i--)
            System.out.print(array.elementAt(i));
    }
}
