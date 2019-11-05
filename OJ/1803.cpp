#include <iostream>
using namespace std;

int main()
{
    int m = 0, n, p, q;
    struct Date
    {
        int year;
        int month;
        int day;
    };
    struct Date date1 = {0, 0, 0};
    cin >> q >> n >> p;
    date1.year = q;
    date1.month = n;
    date1.day = p;
    if (((date1.year % 4 == 0) && (date1.year % 100 != 0)) || (date1.year % 400 == 0))
    {

        for (int i = 1; i < date1.month; i++)
        {

            if (i == 2)
                m += 29;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                m += 30;
            else
                m += 31;
        }
        cout << m + date1.day << endl;
    }
    else
    {

        for (int i = 1; i < date1.month; i++)
        {

            if (i == 2)
                m += 28;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                m += 30;
            else
                m += 31;
        }
        cout << m + date1.day << endl;
    }
    return 0;
}
