#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

const int INF=1e+6;

using namespace std;

char pic[105][105];
int n,m;
int ans=0;

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=n)
        return;
    if(pic[i][j]=='.')
        return;
    if(pic[i][j]=='#')
        pic[i][j]='.';
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main()
{
    scanf("%d %d",&n,&m);
    _for(i,0,n)
    {
        scanf("%s",pic[i]);
    }
    _for(i,0,n)
    {
        _for(j,0,m)
        {
            if(pic[i][j]=='#')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
