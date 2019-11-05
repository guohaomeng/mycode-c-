#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a,b;
    int m,n;
    cin >>m>>n;
    int f[m],g[n];
    for(int i=0;i<m;i++) cin>>f[i];
    for(int i=0;i<n;i++) cin>>g[i];
    int *p2= &f[m-1];
    int *p3= &g[0];
    a= *p2 -*p3;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(f[i]==g[j]){
                a=0;
            }
        }
    }
    if(a<0) a= -a;
    cout << a << endl;
    return 0;
}