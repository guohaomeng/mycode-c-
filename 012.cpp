#include<iostream>
#include<iomanip>
//#include<bits/stdc++.h>
//#include<cstdio>
using namespace std;
#define N 0.000001;
double ans(double x)
{
    double sum=1;
    for(int i = 1; i <=x;i++)
    {
        sum= sum/i;
    }
    return sum;
}
int main()
{
    double i=1,e=1,a;
    while(1){
        a= ans(i++);
        if(a<0.000001) break;
        e+=a;    
            
        
    }
    cout<<setiosflags(ios::fixed)<<setprecision(7)<<e<<endl;
    printf("%.7f\n",e);
    return 0;
}