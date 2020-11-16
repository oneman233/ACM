#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=2147483647;

int n,m,s;
int x,y;
ll val;
ll dis[10010];
ll pic[10010][10010];
bool isask[10010];

void dijkstra()
{
    int start=s;
    isask[start]=true;///起点已经被搜索过
    for(int i=1;i<=n;++i)
        dis[i]=pic[s][i];
        ///init
    for(int j=1;j<=n-1;++j)///计数器，确保每个点都访问到
    {
        int sml=INF;
        for(int i=1;i<=n;++i)
        {
            if(dis[i]<sml&&!isask[i])
            {
                sml=dis[i];
                start=i;
            }
        }
        isask[start]=true;
        ///更新起点值
        for(int i=1;i<=n;++i)
            dis[i]=min(dis[i],dis[start]+pic[start][i]);
    }

}

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            pic[i][j]=INF;
        }
    }
    while(m--)
    {
        cin>>x>>y>>val;
        pic[x][y]=val;
    }
    for(int i=1;i<=n;++i)
        pic[i][i]=0;
    for(int i=1;i<=n;++i)
        dis[i]=INF;
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    return 0;
}
