#include <stdio.h>

int main()
{
    char zi[1001];
    int n,i=0,j=0;//i��j��
    int geshu=0,lie=0;
    int sum=0,cha;
    int lock=0;//����,����պ����е����
    int jishu=0;//��ӡ��ʱ���ڼ�������Ҫ���
    scanf("%d",&n);
    getchar();
    gets(zi);
    while(zi[i]!='\0')
    {
        geshu++;
        i++;
    }//�õ��ַ�����
    while(sum<geshu)
    {
        sum+=n;
        lie++;
    }//�õ���ӡ���������
    cha=sum-geshu;//�м��д���
    //printf("%d %d %d %d",n,geshu,cha,lie);
    if(cha==0)
        lock=1;//������
    for(i=0;i<n-cha;i++)//�ȴ����е�
    {
        for(j=n*(lie-1)+i;jishu<lie;j-=n)
        {
            printf("%c",zi[j]);
            jishu++;
        }
        jishu=0;
        if(lock==0)//δ������
            printf("\n");
        else//�Ѽ�����
        {
            if(i!=(n-cha-1))
                printf("\n");
        }
    }
    jishu=0;
    for(i=0;i<cha;i++)
    {
        printf(" ");//�ȴ�һ���ո�
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
