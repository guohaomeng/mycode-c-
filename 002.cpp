#include <iostream>
#include <string>
using namespace std;

void translate(string &arr1)
{
    int n = arr1.length();
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] <= 'Z' && arr1[i] >= 'A')
        {
            arr1[i] = (char)(arr1[i] + 32);
        }
    }
}
int main()
{
    string str[10000];
    char str1[1000000][10];
    string arr;
    int a, b = 0;
    cin >> arr;
    cin.clear();
    cin.sync();
    int i = 0;
    while ((cin.peek() != '\n') && cin >> str[i])
    {
        i++;
    }
    translate(arr);
    for (int i = 0; i < 10; i++)
    {
        translate(str[i]);
        if (str[i] == arr)
        {
            a++;
            if (b == 0)
            {
                b = i + 1;
            }
        }
    }
    if (a == 0)
    {
        a = -1;
        cout << a << endl;
    }
    else
    {
        b -= 1;
        cout << a <<" "<< b << endl;
    }

    return 0;
}