#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define N 1000005//宏定义，数组长度
int main(void)
{
    int i,j,k,cnt=0;//cnt用来计数
    char a[15],b[N];
    gets(a);//读入需要查找的单词
    gets(b);//读入文章
    for(i=0; b[i]!='\0'; i++)//循环遍历文章
    {
        if(i==0&&b[i]==' ')//文章开头是空格的情况
            continue;
        else if(i==0||b[i-1]==' ')//一个单词一个单词的比较
        {
            for(j=i; j<i+(int)strlen(a); j++)//比较文章中每一个单词和需要查找的单词
            {
                if(a[j-i]==b[j]||(int)fabs(a[j-i]-b[j])==32)//大小写
                    continue;
                else
                    break;
            }
            if(j==i+(int)strlen(a)&&(b[j]==' '))//注意：如果需要查找的单词为to，这里排除了t，top等等的情况
            {
                if(!cnt)
                    k=i;//记录下首次匹配的单词首字母在文章中的位置
                cnt++;//记录下单词出现的次数
            }
        }
    }
    if(cnt)
        printf("%d %d\n",cnt,k);
    else//cnt=0，即单词在文章中没有出现
        printf("-1\n");
}
