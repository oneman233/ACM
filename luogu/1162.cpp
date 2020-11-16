#include <bits/stdc++.h>
using namespace std;

int n;
int a[50][50];

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=n||a[i][j]==1||a[i][j]==2)
        return;
    a[i][j]=2;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

bool check(int x,int y)
{
    int cnt=0;
    for(int i=x;i<n;++i)
    {
        if(a[i][y]==1)
        {
            cnt++;
            break;
        }
    }
    for(int i=x;i>=0;--i)
    {
        if(a[i][y]==1)
        {
            cnt++;
            break;
        }
    }
    for(int i=y;i<n;++i)
    {
        if(a[x][i]==1)
        {
            cnt++;
            break;
        }
    }
    for(int i=y;i>=0;--i)
    {
        if(a[x][i]==1)
        {
            cnt++;
            break;
        }
    }
    if(cnt==4)
        return true;
    else
        return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]==0)
            {
                if(check(i,j))
                {
                    dfs(i,j);
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j];
            if(j!=n-1)
                cout<<" ";
        }
        if(i!=n-1)
            cout<<endl;
    }
    return 0;
}
