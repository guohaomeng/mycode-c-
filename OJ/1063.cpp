#include<iostream>
using namespace std;
int judge(int);
int main()
{
    int a;
    cin >> a;
    if (judge(a) ){
        cout << "prime" << endl;
    } 
    else cout << "not prime" << endl;
    return 0;  
}
int judge(int n){
    int f=1,i;
    for(i=2;i<n/2 && f==1;i++){
        if (n%i ==0) f=0;
    }   
    return f; 
}
    