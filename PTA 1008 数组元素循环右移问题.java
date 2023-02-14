/// PAT (Basic Level) Practice
/// 1008 数组元素循环右移问题
/// 2023-02-14
/// Java 始终不能像 C++ 那般灵活的使用结构体数组......
/// 或许我还没有感受到 Java 语言的伟大之处.

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n, m;
        n = input.nextInt();
        m = input.nextInt();

        Number[] arr = new Number[n];

        for (int i = 0; i < n; i++)
            arr[i] = new Number();

        for (int i = 0; i < n; i++)
            arr[i].first = input.nextInt();

        for (int i = 0; i < n; i++)
            arr[(i + m) % n].second = arr[i].first;

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i].second);
            if (i != n - 1)
                System.out.print(' ');
        }

    }

    static class Number {
        public Integer first;
        public Integer second;

        public Number() {
            this.first = 0;
            this.second = 0;
        }
    }

}
