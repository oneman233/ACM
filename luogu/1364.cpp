#include <bits/stdc++.h>
using namespace std;
const int inf=1000000;

int n;
int p[105];
int dis[105][105];
int l,r;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dis[i][j]=inf;
        }
    }
    ///init;
    for(int i=1;i<=n;++i)
    {
        dis[i][i]=0;
        cin>>p[i]>>l>>r;
        dis[l][i]=1;
        dis[i][l]=1;
        dis[r][i]=1;
        dis[i][r]=1;
    }
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            /*
            if(j!=i&&k!=i&&k!=j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][i]);
            }
            */
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    }
    int ans=inf;
    for(int i=1;i<=n;++i)
    {
        int sum=0;
        for(int j=1;j<=n;++j)
            if(j!=i)
                sum+=p[j]*dis[j][i];
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
