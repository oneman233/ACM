#include <bits/stdc++.h>

using namespace std;

int main()
//�Ա�ͬ����ӣ��Ա���ͬ�����
//�������ҲŽ�������
{
    int n,m;
    int meili[30][30];
    int out[30][30];
    int i,j;
    int maxsum=-1000,maxi=0,maxj=0;
    memset(out,0,sizeof(out));
    memset(meili,0,sizeof(meili));//����
    while(scanf("%d %d",&n,&m))
    {
        maxsum=-1000,maxi=0,maxj=0;
        memset(out,0,sizeof(out));
        memset(meili,0,sizeof(meili));//����
        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++)//��
        {
            for(j=1;j<=m;j++)//��
            {
                scanf("%d",&meili[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(meili[i][j]*meili[i][j+1]<=0)
                    out[i][j]+=abs(meili[i][j+1]);
                else
                    out[i][j]-=abs(meili[i][j+1]);
                //�Ҳ�
                if(meili[i][j]*meili[i][j-1]<=0)
                    out[i][j]+=abs(meili[i][j-1]);
                else
                    out[i][j]-=abs(meili[i][j-1]);
                //���
                if(meili[i][j]*meili[i+1][j]<=0)
                    out[i][j]+=abs(meili[i+1][j]);
                else
                    out[i][j]-=abs(meili[i+1][j]);
                //�²�
                if(meili[i][j]*meili[i-1][j]<=0)
                    out[i][j]+=abs(meili[i-1][j]);
                else
                    out[i][j]-=abs(meili[i-1][j]);
                //�ϲ�
            }
        }
        for(i=1;i<=n;i++)//������С����
        {
            for(j=1;j<=m;j++)//������С����
            {
                if(out[i][j]>maxsum)
                {
                    maxi=i;
                    maxj=j;
                    maxsum=out[i][j];
                }
            }
        }
        printf("%d %d %d\n",maxi,maxj,out[maxi][maxj]);
    }
    return 0;
}
