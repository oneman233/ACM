#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int n,m;
char a[105][105];
int ans=0;

void dfs(int i, int j)
{
    if(i>=n || i<0 || j>=m || j<0)
        return;
    if(a[i][j] != '#')
        return;
    a[i][j] = '.';
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main()
{
    cin>>n>>m;
    _for(i,0,n)
    {
        _for(j,0,m)
        {
            cin>>a[i][j];
        }
    }
    _for(i,0,n)
    {
        _for(j,0,m)
        {
            if(a[i][j] == '#')
            {
                dfs(i, j);
                ++ans;
            }
        }
    }
    cout<<ans;
    return 0;
}
