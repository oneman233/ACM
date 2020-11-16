#include <bits/stdc++.h>
using namespace std;

bool isp(int x)
{
    if(x==1)
        return false;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

int n;
int ans[25];
bool vis[25];

void put()
{
    for(int i=0;i<n;++i){
        printf("%d",ans[i]);
        if(i!=n-1)
            printf(" ");
    }
    printf("\n");
}

void dfs(int num,int idx)
{
    ///put();
    vis[num]=true;
    ans[idx]=num;
    if(idx==n-1)
    {
        if(isp(ans[n-1]+ans[0]))
            put();
        vis[num]=false;
        ans[idx]=0;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i]&&isp(num+i))
            dfs(i,idx+1);
    }
    vis[num]=false;
    ans[idx]=0;
    return;
}

int main()
{
    memset(ans,0,sizeof(ans));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("No");
        return 0;
    }
    dfs(1,0);
    return 0;
}
