#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] + b[i] << endl;
    }

    return 0;
}
