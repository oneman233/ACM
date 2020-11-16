#include <stdio.h>
int main()
{
    int n,a[1000],i,j,max=1,count=0,xiabiao;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)//比较低效的n平方算法
        {
            if(a[j]==a[i])
                count++;
        }
        if(count>max)
        {
            max=count;
            xiabiao=i;
        }
        count=0;
    }
    printf("%d %d",a[xiabiao],max);
    return 0;
}
