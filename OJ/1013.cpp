#include<iostream>
#include <cstdio>

using namespace std;
int main()
{   int i=0;
    int sum =0;
    int a;
    int num[90];
    char c;
    cin>>a;  //��Ҫ�洢��������Ŀ
    while(i<a)
    {
        c=getchar();  //��ȡ�����ַ�
        if((c>='0'&&c<='9')||c=='-')  //������������������
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
