#include <stdio.h>
int main()
{
    int n,u,d,time,height=0;
    scanf("%d %d %d",&n,&u,&d);//d��uȷ���������������������
    for(time=0;height<(n-u);time+=2)
        height+=(u-d);
    printf("%d",time+1);
    return 0;
}
