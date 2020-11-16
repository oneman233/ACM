#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int n,m;
int a[105][105];
int ans=0;

void dfs(int i, int j, int high)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    ans=ans>high?ans:high;
    if(a[i][j] > a[i+1][j])
        dfs(i+1, j, high+1);
    if(a[i][j] > a[i-1][j])
        dfs(i-1, j, high+1);
    if(a[i][j] > a[i][j+1])
        dfs(i, j+1, high+1);
    if(a[i][j] > a[i][j-1])
        dfs(i, j-1, high+1);
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
            dfs(i, j, 1);
        }
    }
    cout<<ans;
    return 0;
}
