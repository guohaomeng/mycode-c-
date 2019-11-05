#include <iostream>
using namespace std;
int a, b, n = 0;
int F(int n)
{
    if (n == 1)
        return a;
    else if (n == 2)
        return b;
    else if ((n > 2) && (n % 2 == 1))
        return F(n - 1) + F(n - 2);
    else if ((n > 2) && (n % 2 == 0))
        return F(n - 1) + F(n - 2) + F(n - 3);
}
int main()
{

    int t = 0;
    cin >> t;
    int aa[t];
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> n;
        aa[i] = F(n);
    }
    for (int i = 0; i < t; i++)
        cout << aa[i] << endl;
    return 0;
}
