#include <stdio.h>
int main()
{
    int i,n,a[100],sum=0;
    a[0]=0;
    a[1]=1;
    scanf("%d",&n);
    for(i=0;i<100;i++)
    {
        if(a[i]>=n)
        {
            printf("%d",i);
            return 0;
        }
        a[i+2]=a[i+1]+a[i];
    }
}
