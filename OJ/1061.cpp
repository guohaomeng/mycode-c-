#include<iostream>
using namespace std;

int yue(int x,int y)
{
   if(x<y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    }
    int r;  
    while((r=x%y)!=0) {
    
        x=y;
        y=r;
        
    }
    return y;  
}
int main()
{
    int a,b,c,d;
   cin >>a>>b ;
    c= yue(a,b);
    d= a*b/c;
    cout << c <<" "<<d << endl;
    return 0;
}
    