#include <stdio.h>
int main()
{
    int n,u,d,time,height=0;
    scanf("%d %d %d",&n,&u,&d);//d＜u确保了蠕虫总是在向上爬行
    for(time=0;height<(n-u);time+=2)
        height+=(u-d);
    printf("%d",time+1);
    return 0;
}
