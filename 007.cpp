#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
int Det(int n, int a[N][N]) //DetΪ����ʽ�ļ�ƣ������������Ǽ���n������ʽ��ֵ
{
    int b[N][N] = {0}, i, j, k, sign = 0, cnt = 0; //�����ά����b�������������ʽ��ÿһ��Ԫ�أ�sign�����ж��ƶ�����cnt������������ʽ��ֵ
    if (n == 1)
        return a[0][0];
    for (i = 0; i < n; i++) //����һ��Ԫ�ص�����ʽ�����ά����b��
    {
        for (k = 0; k < n - 1; k++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (k < i) //a[k][j]λ�ڵ�i�е��Ϸ���ֻ�轫a[k][j]�е�Ԫ����������
                    sign = 0;
                else //a[k][j]λ�ڵ�i�л����·�������������ƺ�����
                    sign = 1;
                b[k][j] = a[k + sign][j + 1]; //ִ���ƶ�������ʵ������ʽ�Ĵ洢
            }
        }
        cnt += a[i][0] * Det(n - 1, b) * pow(-1, i); //����ʽ��ϵ��Ϊ-1��i+j�η�����j=0��ʹ�õݹ飬����һ��Ԫ�صĴ�������ʽ֮�ʹ���cnt��cnt��ֵ��Ϊ����ʽ��ֵ
    }
    return cnt; //�����ķ���ֵcnt��Ϊn������ʽ��ֵ
}
int main(void)
{
    int i, j, n = 0, a[N][N] = {0};
    scanf("%d", &n);
    while (n > 0) //n��ֵ�������0
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]); //��������ʽ
        printf("%dn", Det(n, a));      //�������ʽ��ֵ
        scanf("%d", &n);               //������������������ʽ��ֵ��ֱ��n<=0ʱ��������
    }
}