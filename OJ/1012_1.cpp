#include <iostream>
#include <cstdio>
 using namespace std;
  int f(int n){
    if(n==1||n==2) return 1;
    else return f(n-1)+f(n-2);
 }
int main(){
    //freopen("in.txt","r",stdin);
    int n;
     cin>>n;
     for(int i=1;i<=n;i++){
        int a;
                 cin>>a;
        int ans=f(a);
        cout<<ans<<endl;
    }
     return 0;
 } 