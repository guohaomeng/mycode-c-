#include<iostream>
using namespace std;
int main(){
    int a=2, b=3,n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        sum+=a;
        a+=b;

    }
    cout<<sum<<endl;

    return 0;
}