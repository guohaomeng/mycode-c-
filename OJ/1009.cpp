#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int zimu = 0, zifu = 0, kongge = 0, shuzi = 0, qita = 0, n;
    int i = 0;
    string arry;
    getline(cin, arry);
    int k = strlen(arry.c_str());
    for (int j = 0; j <= k; j++)
    {
        int a;
        a = (int)arry[j];
        if (a == 32)
        {
            kongge++;
        }
        else if (a >= 48 && a <= 57)
        {
            shuzi++;
        }
        else if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        {
            zimu++;
        }

        else
            qita++;
    }
    cout << zimu << endl;
    cout << kongge << endl;
    cout << shuzi << endl;
    cout << qita - 1 << endl;
}