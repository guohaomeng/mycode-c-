#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int judge(int n,int rnt)
{
    if(n==1)
        return rnt;
    int t=n&1?n*3+1:n/2;
    return judge(t,rnt+1);
}
int main(void)
{
    int i,j,m,n;
    while(cin>>i>>j)
    {
        int cnt=0;
        m=max(i,j);
        n=min(i,j);
        for(int k=n;k<=m;k++)
        {
            cnt=max(cnt,judge(k,1));
        }
        cout<<cnt<<endl;
    }
}
