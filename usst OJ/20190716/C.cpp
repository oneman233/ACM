#include <bits/stdc++.h>
using namespace std;

int n,m,t;
int p[105][105];
int sum[105][105];
int ans=0;

int main()
{
    scanf("%d %d %d",&n,&m,&t);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sum[i][j]=p[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int r=0;r<=9&&i+r<=n;++r)
            {
                for(int c=0;c<=9&&j+c<=m;++c)
                {
                    int cal=sum[i+r][j+c]-sum[i+r][j-1]-sum[i-1][j+c]+sum[i-1][j-1]-(r+1)*(c+1)*t;
                    //cout<<i<<' '<<j<<' '<<r<<' '<<c<<' '<<cal<<endl;
                    ans=max(ans,cal);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
/*
5 3 5
2 6 3
10 6 6
5 2 4
1 5 9
10 4 3

*/
