#include<iostream>
#include<string>
using namespace std;

int main()
{
    int j=0;
    char str1[80];
    char str2[80]={0};
    char *p = str1;
    char *p1 = str2;
    cin>>str1;
    for(int i=0;i<80;i++){
        char c = *(p+i);
        if(c=='\0') break;
        if((c<=90&&c>=65)||(c<=122&&c>=97)){
            *(p1+ j ) = c ;
            j++;  
        }
    }
    cout << str2<< endl;
    return 0;
}