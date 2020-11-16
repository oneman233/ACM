#include <bits/stdc++.h>

using namespace std;

int main()
//性别不同则相加，性别相同则相减
//上下左右才叫做相邻
{
    int n,m;
    int meili[30][30];
    int out[30][30];
    int i,j;
    int maxsum=-1000,maxi=0,maxj=0;
    memset(out,0,sizeof(out));
    memset(meili,0,sizeof(meili));//清零
    while(scanf("%d %d",&n,&m))
    {
        maxsum=-1000,maxi=0,maxj=0;
        memset(out,0,sizeof(out));
        memset(meili,0,sizeof(meili));//清零
        if(n==0&&m==0)
            break;
        for(i=1;i<=n;i++)//行
        {
            for(j=1;j<=m;j++)//列
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
                //右侧
                if(meili[i][j]*meili[i][j-1]<=0)
                    out[i][j]+=abs(meili[i][j-1]);
                else
                    out[i][j]-=abs(meili[i][j-1]);
                //左侧
                if(meili[i][j]*meili[i+1][j]<=0)
                    out[i][j]+=abs(meili[i+1][j]);
                else
                    out[i][j]-=abs(meili[i+1][j]);
                //下侧
                if(meili[i][j]*meili[i-1][j]<=0)
                    out[i][j]+=abs(meili[i-1][j]);
                else
                    out[i][j]-=abs(meili[i-1][j]);
                //上侧
            }
        }
        for(i=1;i<=n;i++)//行数由小到大
        {
            for(j=1;j<=m;j++)//列数由小到大
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
