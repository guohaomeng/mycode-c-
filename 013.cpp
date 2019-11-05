#include <iostream>
using namespace std;


int judge2();
int m, n, p, q, a, b, c, d, e = 0;
int m1[100] = {0, 0, 0, 0};
int n1[100] = {0, 0, 0, 0};
int e1[100] = {0, 0, 0, 0};
int judge2()
{
    for (int j = m; j <= n; j++)
    { //对每一个数进行判断
        int i = j;
        int arr[3000];
        c = 0;
        for (int p = 0;; p++)
        {
            arr[p] = i;
            c++;
            if (i == 1)
                break;
            else if (i % 2 == 0)
                i /= 2;
            else
                i = i * 3 + 1;
        }
        if (e < c)
            e = c; //e为最大周期长度
    }
}

int main()
{

    for (int i = 0; i < 4; i++)
    {
        cin >> m1[i] >> n1[i];
        m = m1[i];
        n = n1[i];
        judge2();
        e1[i] = e;
        e = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << m1[i] << " " << n1[i] << " " << e1[i] << endl;
    }
}