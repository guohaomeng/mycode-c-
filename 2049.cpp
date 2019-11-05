#include <iostream>
#include <iomanip>
using namespace std;
double jiecheng(double n)
{
    double sum = 1;
    for (double i = 1; i < n; i++)
    {
        sum = sum/i;
    }
    return sum;
}
int main()
{
    double e = 0;
    for (double i = 1;; i++)
    {
        double m = jiecheng(i);
        if (m < 0.000001)
        {
            break;
        }
        e += m;
    }
    cout << setiosflags(ios::fixed) << setprecision(7) << e << endl;
    return 0;
}
