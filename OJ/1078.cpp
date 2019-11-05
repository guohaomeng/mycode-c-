#include<iostream>
using namespace std;

int main()
{
    string str1[3];
    cin >> str1[0];
    cin >> str1[1];
    cin >> str1[2];
    for(int i=0;i<3;i++){
        string str2,str3;
        if(str1[i]<str1[0]){
            str2= str1[0];
            str1[0]= str1[i];
            str1[i] = str2;
        }
        if(str1[i]>str1[2]){
            str3= str1[2];
            str1[2]= str1[i];
            str1[i] = str3;
        }
    }
    cout <<str1[0]<< endl;
    cout <<str1[1]<< endl;
    cout <<str1[2]<< endl;
    
    return 0;
}