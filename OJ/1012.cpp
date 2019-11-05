#include <iostream>
#include <cstdio>
using namespace std;
int f(int, int, int);
int main()
{
    int m;
    cin >> m;
    int a2[33], b2[33];
    for (int i = 0; i < m; i++)
    {
        int a1, b1, c1, n;
        cin >> a1 >> b1 >> n;
        c1 = f(a1, b1, n);
        a2[i] = c1;
    }
    for (int j = 0; j < m; j++)
    {
        cout << a2[j] << endl;
    }
}
int f(int x, int y, int z)
{
    if (z == 1)
    {
        return x;
    }
    else if (z == 2)
    {
        return y;
    }
    else if (z > 2 && z % 2 == 1)
    {
        return f(x, y, z - 1) + f(x, y, z - 2);
    }
    else
    {
        return f(x, y, z - 1) + f(x, y, z - 2) + f(x, y, z - 3);
    }
}