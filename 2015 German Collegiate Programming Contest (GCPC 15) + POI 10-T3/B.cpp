#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define elif else if

int n;
vector<int> e[1005];
bool vis[1005];
int lk[1005];

bool dfs(int x)
{
    for(auto i:e[x])
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(lk[i]==-1||dfs(lk[i]))
            {
                lk[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        int x,y;
        scanf("%d",&x);
        for(int j=0;j<x;++j)
        {
            scanf("%d",&y);
            e[i].push_back(y);
        }
    }
    for(int i=0;i<n;++i) lk[i]=-1;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    printf("%d",n-ans);
    return 0;
}
/*
4
1 1
1 2
0
1 1
 */
