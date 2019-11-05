#include <iostream>
#include <string>
using namespace std;

int b =0;
int m=0;
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
    string arr;
    int a = 0;
    cin >> arr;
    cin.clear();
    cin.sync();
    int j = 0;
    while (((cin.peek() != '\n') && (cin>> str[j])))
    {
        if(cin.peek()==' ') m++;
        j++;
    }
    translate(arr);
    for (int i = 0; i < j; i++)
    {
        cout<<str[i]<<endl;
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
        //b -= 1;
        for(int k=0;k<b;k++)
        {
            m += str[k].length();
        }
        cout << a <<" "<< m-2 << endl;
    }

    return 0;
}