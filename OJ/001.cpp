#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Student {
    public:
    void input(){
        input1();
    }
    float calculate(){
        calculate1();
    }
    void output(){
        output1();
    }
    private:
    char name;
    int age;
    string id;
    int score1;
    int score2;
    int score3;
    int score4;
    float score;
    
    /*friend void input(Student &student);
    friend float calculate(Student &student);
    friend void output(Student &student); */
    

    void input1(){
        //cin.getline(name,20,',');
        //getline(cin,name);
        
        cin.get(name);
        
        cin>>age>>id>>score1>>score2>>score3>>score4;
        while(name != ',')
        {
            cout<<name;
            cin.get(name);
            
        }
    }
     float calculate1(){
        score = (score1+score2+score3+score4)/4;
    }
     void output1(){
         
        cout<<name<<endl;
        cout<<score<<endl;
        cout<<name<<","<<age<<id<<score;
    }
    
};
    /*void input(Student &student){
        getline(cin,student.name);
        cin>>student.age>>student.id>>student.score1>>student.score2>>student.score3>>student.score4;
    }
     float calculate(Student &student){
        student.score = (student.score1+student.score2+student.score3+student.score4)/4;
    }
     void output(Student &student){
        cout<<student.name<<student.age<<student.id<<student.score;
    }*/
int main() {
Student student;        // 定义类的对象
student.input();        // 输入数据
student.calculate();    // 计算平均成绩
student.output();       // 输出数据
return 0;
}
