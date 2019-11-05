#include <iostream>
#include <string>
using namespace std;
int m, n, p;
struct Student
{
    string id;
    string name;
    int score1;
    int score2;
    int score3;

} student[99];
void input(Student *p)
{
    cin >> p->id >> p->name >> p->score1 >> p->score2 >> p->score3;
}
void print(Student *p1)
{
    cout << p1->id << "," << p1->name << "," << p1->score1 << "," << p1->score2 << "," << p1->score3 << endl;
}
int main()
{

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        Student *p = &student[i];
        input(p);
    }
    for (int i = 0; i < m; i++)
    {
        Student *p1 = &student[i];
        print(p1);
    }
    return 0;
}
