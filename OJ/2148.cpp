#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N][N];
int main()
{
    double ave[N]= {0},value[N];
    int t,n,k;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n>>k;
        for(int j=1; j<=n; j++)
        {
            cin>>dp[i][j];
            ave[i]+=dp[i][j];
        }
        ave[i]/=n;
        value[i]=ave[i];
        for(int j=1; j<=n; j++)
        {
            if(dp[i][j]>=ave[i])
            {
                value[i]=value[i]-(dp[i][j]-ave[i])*k/100;
            }
        }
    }
    for(int i=1; i<=t; i++)
        printf("%.6f\n",value[i]);
    return 0;
}
