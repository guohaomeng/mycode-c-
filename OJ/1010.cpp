#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    long double n=1,sum =0;
    for (int i = 1; i <= 30; i++)
    {
        n *= i;
        sum += n;
    }
    cout <<setiosflags(ios::scientific)<<setprecision(2) <<sum<< endl;
    return 0;
}
