#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, n;
    string arr1;
    getline(cin, arr1);
    n = arr1.length();
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] <= 'Z' && arr1[i] >= 'A')
        {
            arr1[i] = (char)(arr1[i] + 32);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i];
    }

    return 0;
}