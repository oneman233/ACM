#include <stdio.h>
int pow(int n)//����10��n�η�
{
    int i,result=1;
    for(i=0;i<n;i++)
        result*=10;
    return result;
}
int haha(int a, int b)
{
    int i,sum=0;
    for(i=0;i<=b;i++)//����ĳһ����,ѭ��b��
        sum+=a*pow(i);
    return sum;
}
int main()
{
    int j,a,n,sum=0;
    scanf("%d %d",&a,&n);
    for(j=0;j<n;j++)
        sum+=haha(a,j);
    printf("s = %d",sum);
    return 0;
}
