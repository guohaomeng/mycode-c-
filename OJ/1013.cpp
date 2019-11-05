#include<iostream>
#include <cstdio>

using namespace std;
int main()
{   int i=0;
    int sum =0;
    int a;
    int num[90];
    char c;
    cin>>a;  //想要存储的数的数目
    while(i<a)
    {
        c=getchar();  //获取输入字符
        if((c>='0'&&c<='9')||c=='-')  //输入正整数、负整数
		{
			ungetc(c,stdin);
			cin>> num[i++];
		}
    }

        for(int j=0;j<i;j++)
       {
           int b = num[j];
           if(b %2 ==0){
               sum += b;
           }
        }
        cout<<sum<<endl;
      return 0;
    }
