#include <stdio.h>
int main()
{
    int n,a[10],max,i,j,mid;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        max=i;//ѡ������ľ����Ǽ�¼�±�,�����ð����������˺ܶ಻��Ҫ�ıȽϹ���
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[max])
                max=j;
        }
        if(max!=i)
        {
            mid=a[max];
            a[max]=a[i];
            a[i]=mid;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i!=n-1)
            printf(" ");
    }
    return 0;
}
