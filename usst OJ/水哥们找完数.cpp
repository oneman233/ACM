#include <iostream>

using namespace std;

bool wanshu(int a)
{
    if(a==1)
        return false;
    int sum=0,i;
    for(i=1;i<a;i++)
    //从因子1开始检查，直到自己减一
    {
        if(a%i==0)
            sum+=i;
            //求出所有因子之和
    }
    if(sum==a)
        return true;
    else
        return false;
}

void print(int a)
//打印完数，不考虑回车
{
    printf("%d = ",a);
    //打印等号左边
    int i,last;
    for(i=1;i<a;i++)
    //找到除自身外的最后一个因子
    {
        if(a%i==0)
        last=i;
    }
    for(i=1;i<a;i++)
    {
        if(a%i==0&&i!=last)
            printf("%d + ",i);
        else if(a%i==0&&i==last)
            printf("%d",i);
        else;
    }
}

int main()
{
    int wan[4];
    //把完数打表
    int m,n;
    int i=1,j=0;
    //从i=1开始找完数，j控制数组下标
    //其实1都可以不用找的，甚至可以从6开始
    //并且实际上所有的质数都一定不是完数
    int geshu=0,tail;
    while(j<4)
    {
        if(wanshu(i))
        {
            wan[j]=i;
            j++;
        }
        i++;
    }
    //第五个完数就飞了
    //i--应该是第四个完数
    scanf("%d %d",&m,&n);
    for(i=0;i<4;i++)
    {
        if(wan[i]>=m&&wan[i]<=n)
        {
            geshu++;
            tail=i;
            //找到输出的完数个数和最后一个输出的完数下标
        }
    }
    if(geshu==0)
    {
        printf("None");
        return 0;
    }
    else
    {
        for(i=tail-geshu+1;i<=tail;i++)
        {
            print(wan[i]);
            if(i!=tail)
                printf("\n");
        }
    }
    return 0;
}
