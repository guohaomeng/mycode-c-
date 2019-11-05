#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Student
{
public:
    void input()
    {
        scanf("%[^,],%d,%[^,],%f,%f,%f,%f", &name, &age, &id, &s1, &s2, &s3, &s4);
    }
    void calculate()
    {
        s = (s1 + s2 + s3 + s4) / 4;
    }
    void output()
    {
        printf("%s,%d,%s,%g\n", name, age, id, s);
    }

private:
    char name[20];
    int age;
    char id[20];
    float s1;
    float s2;
    float s3;
    float s4;
    float s;
};
int main()
{
    Student student;     // 定义类的对象
    student.input();     // 输入数据
    student.calculate(); // 计算平均成绩
    student.output();    // 输出数据
}