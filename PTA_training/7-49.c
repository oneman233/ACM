#include <stdio.h>
int main()
{
    int mid,i,j,n,k,count=0,a[100];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                mid=a[j];
                a[j]=a[j+1];
                a[j+1]=mid;
            }
        }
        count++;
        if(count==k)
            break;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i!=n-1)
            printf(" ");
    }
    return 0;
}
