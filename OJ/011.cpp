#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define N 1000005//�궨�壬���鳤��
int main(void)
{
    int i,j,k,cnt=0;//cnt��������
    char a[15],b[N];
    gets(a);//������Ҫ���ҵĵ���
    gets(b);//��������
    for(i=0; b[i]!='\0'; i++)//ѭ����������
    {
        if(i==0&&b[i]==' ')//���¿�ͷ�ǿո�����
            continue;
        else if(i==0||b[i-1]==' ')//һ������һ�����ʵıȽ�
        {
            for(j=i; j<i+(int)strlen(a); j++)//�Ƚ�������ÿһ�����ʺ���Ҫ���ҵĵ���
            {
                if(a[j-i]==b[j]||(int)fabs(a[j-i]-b[j])==32)//��Сд
                    continue;
                else
                    break;
            }
            if(j==i+(int)strlen(a)&&(b[j]==' '))//ע�⣺�����Ҫ���ҵĵ���Ϊto�������ų���t��top�ȵȵ����
            {
                if(!cnt)
                    k=i;//��¼���״�ƥ��ĵ�������ĸ�������е�λ��
                cnt++;//��¼�µ��ʳ��ֵĴ���
            }
        }
    }
    if(cnt)
        printf("%d %d\n",cnt,k);
    else//cnt=0����������������û�г���
        printf("-1\n");
}
