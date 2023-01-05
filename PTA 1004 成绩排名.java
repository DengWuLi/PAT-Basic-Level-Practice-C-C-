/// PTA 1004 成绩排名
/// 2023/01/05

import java.util.Scanner;

class Student {
    String name, ID;
    int score;
}

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Student maxStudent = new Student(), minStudent = new Student();
        maxStudent.score = -1;
        minStudent.score = Integer.MAX_VALUE;
        String tempName, tempID;
        int tempScore;
        for (int i = 0; i < n; i++) {
            tempName = scanner.next();
            tempID = scanner.next();
            tempScore = scanner.nextInt();
            if (tempScore > maxStudent.score) {
                maxStudent.name = tempName;
                maxStudent.ID = tempID;
                maxStudent.score = tempScore;
            }
            if (tempScore < minStudent.score) {
                minStudent.name = tempName;
                minStudent.ID = tempID;
                minStudent.score = tempScore;
            }
        }
        System.out.printf("%s %s\n", maxStudent.name, maxStudent.ID);
        System.out.printf("%s %s\n", minStudent.name, minStudent.ID);
    }


}
