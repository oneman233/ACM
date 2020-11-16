#include <stdio.h>
int main()
{
    int n,sum=1,i=1,cha,j,lie,kong;
    char pic;
    scanf("%d %c",&n,&pic);
    while(sum<=n)
    {
        i+=2;
        sum+=2*i;
    }
    sum-=2*i;
    i-=2;
    cha=n-sum;
    lie=i;//储存最大列数
    kong=0;//储存空格数
    for(;i>1;i-=2)
    {
        for(j=0;j<kong;j++)
            printf(" ");
        for(j=0;j<i;j++)
            printf("%c",pic);
        printf("\n");
        kong++;
    }
    for(j=0;j<kong;j++)
        printf(" ");
    printf("%c\n",pic);//目前i等于1
    kong--;
    i+=2;
    for(;i<=lie;i+=2)
    {
        for(j=0;j<kong;j++)
            printf(" ");
        for(j=0;j<i;j++)
            printf("%c",pic);
        kong--;
        printf("\n");
    }
    printf("%d",cha);
}
