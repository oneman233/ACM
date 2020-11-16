#include <stdio.h>

int main()
{
    char zi[1001];
    int n,i=0,j=0;//i行j列
    int geshu=0,lie=0;
    int sum=0,cha;
    int lock=0;//加锁,如果刚好满行的情况
    int jishu=0;//打印列时用于计数，需要清空
    scanf("%d",&n);
    getchar();
    gets(zi);
    while(zi[i]!='\0')
    {
        geshu++;
        i++;
    }//得到字符总数
    while(sum<geshu)
    {
        sum+=n;
        lie++;
    }//得到打印所需的列数
    cha=sum-geshu;//有几行打不满
    //printf("%d %d %d %d",n,geshu,cha,lie);
    if(cha==0)
        lock=1;//激活锁
    for(i=0;i<n-cha;i++)//先打满行的
    {
        for(j=n*(lie-1)+i;jishu<lie;j-=n)
        {
            printf("%c",zi[j]);
            jishu++;
        }
        jishu=0;
        if(lock==0)//未激活锁
            printf("\n");
        else//已激活锁
        {
            if(i!=(n-cha-1))
                printf("\n");
        }
    }
    jishu=0;
    for(i=0;i<cha;i++)
    {
        printf(" ");//先打一个空格
        for(j=geshu-n+i;jishu<lie-1;j-=n)
        {
            printf("%c",zi[j]);
            jishu++;
        }
        jishu=0;
        if(i!=(cha-1))
            printf("\n");
    }
    return 0;
}
