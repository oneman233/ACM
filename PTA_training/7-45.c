#include <stdio.h>
int main()
{
    int a,b,count=0,i,sum=0,flag=1;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
    {
        printf("% 5d",i);
        sum+=i;
        count++;
        if(count==5)
        {
            printf("\n");
            count=0;
            if(i==b)
                flag=0;
        }
        if(flag!=0&&i==b)
            printf("\n");
    }
    printf("Sum = %d",sum);
}
