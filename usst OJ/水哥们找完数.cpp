#include <iostream>

using namespace std;

bool wanshu(int a)
{
    if(a==1)
        return false;
    int sum=0,i;
    for(i=1;i<a;i++)
    //������1��ʼ��飬ֱ���Լ���һ
    {
        if(a%i==0)
            sum+=i;
            //�����������֮��
    }
    if(sum==a)
        return true;
    else
        return false;
}

void print(int a)
//��ӡ�����������ǻس�
{
    printf("%d = ",a);
    //��ӡ�Ⱥ����
    int i,last;
    for(i=1;i<a;i++)
    //�ҵ�������������һ������
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
    //���������
    int m,n;
    int i=1,j=0;
    //��i=1��ʼ��������j���������±�
    //��ʵ1�����Բ����ҵģ��������Դ�6��ʼ
    //����ʵ�������е�������һ����������
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
    //����������ͷ���
    //i--Ӧ���ǵ��ĸ�����
    scanf("%d %d",&m,&n);
    for(i=0;i<4;i++)
    {
        if(wan[i]>=m&&wan[i]<=n)
        {
            geshu++;
            tail=i;
            //�ҵ�������������������һ������������±�
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
