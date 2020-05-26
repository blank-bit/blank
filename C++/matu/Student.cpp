// 设计一个学生类Student，包含学生学号（最长10位）、姓名（不用支持中文最长12位）、三门课程成绩等基本信息，
// 计算每门课程学生的平均成绩。

// 需实现Student的display成员函数，依次输出学号 姓名 和三门课的成绩，每个输出以空格隔开
// 成员函数 average1 ,average2 ,average3 ,分别返回三门课的平均成绩。

// Student类的使用方法如下所示，在你的代码中除了实现Student类，还需引入以下代码：

#include <iostream>
#include <cstring>
using namespace std;

double sum1, sum2, sum3, i = 0;

class Student
{
private:
    char name[10];
    char num[12];
    int grade1, grade2, grade3;

public:
    Student(char *Name, char *Num, int Grade1, int Grade2, int Grade3)
    {
        strcpy(name, Name);
        strcpy(num, Num);
        grade1 = Grade1;
        grade2 = Grade2;
        grade3 = Grade3;
        sum1 += Grade1;
        sum2 += Grade2;
        sum3 += Grade3;
        i++;
    }
    double average1() { return sum1 / i; }
    double average2() { return sum2 / i; }
    double average3() { return sum3 / i; }
    void display()
    {
        cout << name << ' ' << num << ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << endl;
    }
};

int main()
{
    Student *stu1, *stu2, *stu3;
    char name1[10], name2[10], name3[10];
    char num1[12], num2[12], num3[12];
    int grade1[3], grade2[3], grade3[3];
    cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
    cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
    cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
    stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
    stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
    stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();

    cout << "The average grade of course1:" << stu2->average1() << endl;
    cout << "The average grade of course2:" << stu2->average2() << endl;
    cout << "The average grade of course3:" << stu2->average3() << endl;

    delete stu1;
    delete stu2;
    delete stu3;

    return 0;
}