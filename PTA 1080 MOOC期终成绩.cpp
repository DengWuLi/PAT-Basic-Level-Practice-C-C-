/* PTA 1080 MOOC期终成绩
 * 2022/07/23
 * 第一段代码会超时, 原因未知; 第二段代码可以AC, 使用了<map>这个库函数
 * */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int programming_grade{-1};
    int mid_term_grade{-1};
    int final_grade{-1};
    int grade{-1};
};

bool Comp(const Student &a, const Student &b)
{
    if (a.grade == b.grade)
        return a.name < b.name;  //name从小到大
    else
        return a.grade > b.grade;  //从大到小排序
}

bool CmpName(const Student &a, const Student &b)
{
    return a.name > b.name;
}

void BinarySearch(const string &name, int grade, int flag, vector<Student> &stu)
{
    int left = 0, right = stu.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (stu[mid].name < name)
            right = mid - 1;
        else if (stu[mid].name > name)
            left = mid + 1;
        else
        {
            if (flag == 1)  //表示输入期中考试成绩
                stu[mid].mid_term_grade = grade;
            else
                stu[mid].final_grade = grade;
            return;  //直接跳出此函数
        }
    }

    //如果找不到这个人
    Student temp;
    temp.name = name;
    if (flag == 1)  //表示输入期中考试成绩
        temp.mid_term_grade = grade;
    else
        temp.final_grade = grade;
    stu.push_back(temp);
}

int main()
{

//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int P, M, N;
    cin >> P >> M >> N;

    vector<Student> stu;
    for (int i = 0; i < P; i++)
    {
        Student temp;
        cin >> temp.name >> temp.programming_grade;
        stu.push_back(temp);
    }

    sort(stu.begin(), stu.end(), CmpName);  //按照姓名排序

    string temp_2;
    int temp_3;

    for (int i = 0; i < M; i++)
    {

        cin >> temp_2 >> temp_3;
        BinarySearch(temp_2, temp_3, 1, stu);
        sort(stu.begin(), stu.end(), CmpName);  //每次添加新的人员之后都要重新排序
    }

    for (int i = 0; i < N; i++)
    {
        cin >> temp_2 >> temp_3;
        BinarySearch(temp_2, temp_3, 2, stu);
        sort(stu.begin(), stu.end(), CmpName);  //每次添加新的人员之后都要重新排序
    }

    //int count = 0;

    vector<Student> stu_2;

    for (auto &i: stu)
    {
        double temp_grade;
        if (i.mid_term_grade > i.final_grade)
        {
            temp_grade = 0.4 * double(i.mid_term_grade) + 0.6 * double(i.final_grade);
            if (temp_grade - int(temp_grade) > 0.5)
                i.grade = int(temp_grade) + 1;
            else
                i.grade = int(temp_grade);
        }
        else
            i.grade = i.final_grade;

        if (i.grade >= 60 && i.programming_grade >= 200)
            stu_2.push_back(i);
    }

    sort(stu_2.begin(), stu_2.end(), Comp);
    for (auto const &i: stu_2)
        cout << i.name << " " << i.programming_grade << " " << i.mid_term_grade << " " << i.final_grade << " "
             << i.grade << "\n";
//    printf("%s %d %d %d %d\n",
//           i.name.c_str(),
//           i.programming_grade,
//           i.mid_term_grade,
//           i.final_grade,
//           i.grade);
}

/* PTA 1080 MOOC期终成绩
 * 2022/07/23
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Grade
{
    int programming_grade{-1};
    int mid_term_grade{-1};
    int final_grade{-1};
    int grade{-1};
};

struct Student
{
    string name;
    int programming_grade{-1};
    int mid_term_grade{-1};
    int final_grade{-1};
    int grade{-1};
};

bool Comp(const Student &a, const Student &b)
{
    if (a.grade == b.grade)
        return a.name < b.name;  //name从小到大
    else
        return a.grade > b.grade;  //从大到小排序
}

int main()
{
    int P, M, N;
    cin >> P >> M >> N;
    map<string, Grade> stu;
    string temp_name;
    int temp_grade;
    while (P--)
    {
        cin >> temp_name >> temp_grade;
        stu[temp_name].programming_grade = temp_grade;
    }

    while (M--)
    {
        cin >> temp_name >> temp_grade;
        stu[temp_name].mid_term_grade = temp_grade;
    }

    while (N--)
    {
        cin >> temp_name >> temp_grade;
        stu[temp_name].final_grade = temp_grade;
    }

    vector<Student> student;
    for (auto i: stu)
    {
        Student temp_student;
        temp_student.name = i.first;
        temp_student.programming_grade = i.second.programming_grade;
        temp_student.mid_term_grade = i.second.mid_term_grade;
        temp_student.final_grade = i.second.final_grade;

        double temp_grade;
        if (temp_student.mid_term_grade > temp_student.final_grade)
        {
            temp_grade = 0.4 * double(temp_student.mid_term_grade) + 0.6 * double(temp_student.final_grade);
            if (temp_grade - int(temp_grade) > 0.5)
                temp_student.grade = int(temp_grade) + 1;
            else
                temp_student.grade = int(temp_grade);
        }
        else
            temp_student.grade = temp_student.final_grade;
        student.push_back(temp_student);
    }
    sort(student.begin(), student.end(), Comp);
    for (auto const &i: student)
        if (i.grade >= 60 && i.programming_grade >= 200)
            printf("%s %d %d %d %d\n",
                   i.name.c_str(),
                   i.programming_grade,
                   i.mid_term_grade,
                   i.final_grade,
                   i.grade);
}
