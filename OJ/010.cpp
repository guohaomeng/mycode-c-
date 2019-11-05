#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 10005 //宏定义，数组长度

int main(void)
{
    int c, d, j, k = 0; //cnt用来计数
    char a2[15], b2[N][10];
    cin >> a2;
    cin.clear();
    cin.sync(); //读入给定单词
    while ((cin.peek() != '\n') && cin >> b2[k])
    {
        k++;
    } //读入文章
    for (int m = 0; m < k; m++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a2[i] <= 'Z' && a2[i] >= 'A')
            {
                a2[i] = (char)(a2[i] + 32);
            }
            else
            {
                /* code */
            }
            if (b2[j][i] <= 'Z' && b2[j][i] >= 'A')
            {
                b2[j][i] = (char)(b2[j][i] + 32);
            }
            else
            {
                /* code */
            }

            if (a2[i] == b2[j][i])
            {
                c++;
                if (d == 0)
                    d = i + 1;
                else
                {
                    /* code */
                }
            }
            else
            {
                /* code */
            }
            j++;

        }
        
    }
    if (c == 0)
        cout << "-1" << endl;
    else
        cout << c << " " << d - 1 << endl;
}
/*

#include <bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;
#define N 10005 //宏定义，数组长度

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
int main(void)
{
    int c, d, j = 0; //cnt用来计数
    char a2[15], b2[N][10];
    cin >> a2;
    string a1 = a2;
    translate(a1);
    cin.clear();
    cin.sync(); //读入给定单词
    while ((cin.peek() != '\n') && cin >> b2[j])
    {
        j++;
    } //读入文章
    for (int i = 0; i < 10; i++)
    {
        string b1 = b2[i];
        translate(b1);
        if (b1 == a1)
        {
            c++;
            if (d == 0)
                d = i + 1;
        }
    }
    if (c == 0)
        cout << "-1" << endl;
    else
        cout << c << " " << d - 1 << endl;
}


 */