#include <stdio.h>
int main()
{
    int n,i,j;//i�����У�j������
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d*%d=%-4d",j,i,i*j);
        printf("\n");
    }
    return 0;
}
