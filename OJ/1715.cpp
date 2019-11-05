#include <iostream>
using namespace std;

class Shape
{
public:
    double a, b, q, c;
};
class Rectangle : public Shape
{
public:
    void GetArea()
    {
        cin >> a >> b;
        c = a * b;
    }
};
class Square : public Rectangle
{
};
class Circle : public Shape
{
public:
    double pi = 3.14;
    double c, d;
    void GetArea()
    {
        cin >> c;
        d = pi * c * c;
    }
};
int main()
{
    Shape m;
    Rectangle n;
    Circle p;
    n.GetArea();
    p.GetArea();
    cout << n.c << endl;
    cout << p.d << endl;
    return 0;
}
