#include <iostream>
using namespace std;
int judge(int, int);
int T, j = 0;
string str[1000];
int main()
{

    cin >> T;
    int arr1[T], arr2[T];
    for (j = 0; j < T; j++)
    {
        int a, b;
        cin >> a >> b;
        arr1[j] = a;
        arr2[j] = b;
        judge(arr1[j], arr2[j]);
    }
    for (int i = 0; i < T; i++)
    {

        cout << str[i] << endl;
    }

    return 0;
}
int judge(int x, int y)
{
    int Y=y, M=y;

    for (int i = 0;; i++)
    {
        Y = x - y;
        if (Y <= 0)
        {
            str[j] = "Yui";
            break;
        }
        M = Y - y;
        if (M <= 0)
        {
            str[j] = "Mio";
            break;
        }
        x = M;
    }

    return 0;
}