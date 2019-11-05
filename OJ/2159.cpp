#include<iostream>
using namespace std;
int ans(int,int,int);
int main(){
    int T,n,m,x,j;
    cin>>T;
    int arr1[T], arr2[T],arr3[T],arr4[T];
    for (j = 0; j < T; j++)
    {
        int a, b,c;
        cin >> a >> b >>c;
        arr1[j] = a;
        arr2[j] = b;
        arr3[j] = c;
        arr4[j] = ans(arr1[j],arr2[j],arr3[j]);
    }
    for(int i=0;i<T;i++){
        cout<<arr4[i]<<endl;
    }

    return 0;
}
int ans(int x,int y,int z){
    if((x+y)%2 ==0) return (x+y)/z -1;
    else return (x+y)/z;
    
}