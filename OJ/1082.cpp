#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,m,a;
    string str1;
    cin>>n;
    cin>>str1;
    cin>>m;
    a = str1.length();
    string str2 = str1.substr(m-1,n-m+1);
    cout<<str2<<endl;
    
    return 0;
}