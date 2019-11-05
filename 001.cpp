#include <stdio.h>
int main()
{
    // 定义相乘数字i,j以及结果result
    int i, j, result;
    for (i = 9; i > 0; i--)
    {
        for (j = 1; j < i + 1; j++)
        {
            result = i * j;
            printf("%d*%d=%d    ", i, j, result);
        }
        printf("\n");
    }
    return 0;
}