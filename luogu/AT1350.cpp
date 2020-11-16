#include <bits/stdc++.h>
using namespace std;

int n,m;
char pic[510][510];
bool ans=false;

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m||pic[i][j]=='#')
        return;
    if(pic[i][j]=='g')
    {
        ans=true;
        return;
    }
    pic[i][j]='#';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>pic[i][j];
        }
    }
    int sx,sy;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(pic[i][j]=='s')
            {
                pic[i][j]='.';
                sx=i;sy=j;
                break;
            }
        }
    }
    dfs(sx,sy);
    if(ans)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
