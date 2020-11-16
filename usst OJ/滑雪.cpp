#include <bits/stdc++.h>
using namespace std;

int h[105][105];
int n,m;
int ans=0;

void dfs(int i,int j,int len)
{
    if(i<0||i>=n||j<0||j>=m)
        return;
    ans=max(ans,len);
    if(h[i][j]>h[i-1][j])
        dfs(i-1,j,len+1);
    if(h[i][j]>h[i+1][j])
        dfs(i+1,j,len+1);
    if(h[i][j]>h[i][j-1])
        dfs(i,j-1,len+1);
    if(h[i][j]>h[i][j+1])
        dfs(i,j+1,len+1);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>h[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dfs(i,j,1);
        }
    }
    cout<<ans;
    return 0;
}
