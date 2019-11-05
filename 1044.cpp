#include<iostream>
using namespace std;
int main(){
    int money,price;
    cin>>money;
    switch((money-1)/100000){
        case 0 :price= money*(0.1);break;
        case 1 :price =100000*(0.1)+ (money-100000)*(0.075);break;
        case 2:;
        case 3 :price =200000*(0.1)+ (money-200000)*(0.05);break;
        case 4:;
        case 5:price =400000*(0.1)+(money-400000)*(0.03);break;
        case 6:;
        case 7:;
        case 8:;
        case 9: price = 600000*(0.1) +(money-600000)*(0.015);break;
        case 10:price = 1000000*(0.1) +(money-1000000)*(0.01);
        default :price = 1000000*(0.1) +(money-1000000)*(0.01);
    }
    cout<<price<<endl;
}