#include <iostream>


using namespace std;


class Student
{
public:
	void get();
	void display();
private:
	int age;
	string name;
};


void Student::get()
{
	cin>>age>>name;
}


void Student::display()
{
	cout<<"age:"<<age<<endl;
	cout<<"name:"<<name<<endl;
}


int main()
{
	Student stud;
	stud.get();
	stud.display();


	return 0;
}