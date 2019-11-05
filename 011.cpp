#include<iostream>
using namespace std;
int arr[10];

int main(){
    int*p=arr;
    shuru(p);
    compare(p);
    shuchu(p);
}
int shuru(int *p3){
    for(int i=0;i<=9;i++){
        cin>>*(p3[i]);
    }
}
int compare(int *p1){
    for(int i=1;i<=9;i++){
        if(p[0]>arr[i]) arr[0]=arr[i];
    }
    for(int i=0;i<=8;i++){
        if(arr[9]<arr[i]) arr[9]=arr[i];
    }
}
int shuchu(int *p2){
    for(int i=0;i<=9;i++){
        cout<<arr[i]<<" ";
    }
}