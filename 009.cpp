#include <iostream>
using namespace std;
int findmax(int x, int y)
{
    return (x > y) ? x : y;
}
int main()
{
    int a, b, c, temp, max;
    cin >> a >> b >> c;
    temp = findmax(a, b);
    max = findmax(temp, c);
    cout << max << endl;
}