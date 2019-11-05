#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    double d;
    cin >> a >> b >> c;
    d = (a + b + c) / 3;
    cout << setiosflags(ios::fixed) << setprecision(3) << d << endl;
}