#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
const int Max=1000000;

struct point
{
    int x,y;
}s,f,wall[50];
int n,m,t;
bool vis[50][50];///记录有没有被访问过
int ans=0;

bool ok(int x,int y)
///检查可不可以通过
{
    if(x<1||x>n||y<1||y>m)
        return false;
    _for(i,0,t)
        if(wall[i].x==x&&wall[i].y==y)
            return false;
    return true;
}

void dfs(int i,int j)
{
    if(!ok(i,j)||vis[i][j])
        return;
    if(i==f.x&&j==f.y)
    {
        ans++;
        return;
    }
    else
    {
        vis[i][j]=true;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
        vis[i][j]=false;
    }
}

int main()
{
    cin>>n>>m>>t;
    cin>>s.x>>s.y>>f.x>>f.y;
    _for(i,0,t)
        cin>>wall[i].x>>wall[i].y;
    dfs(s.x,s.y);
    cout<<ans;
    return 0;
}
