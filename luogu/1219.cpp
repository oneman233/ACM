#include<bits/stdc++.h>
using namespace std;

int n;
int ans[100];
bool vis[100],xpy[100],xmy[100];
int cnt=0;

int pic[100][100];

void put()
{
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i];
        if(i!=n)
            cout<<" ";
    }
    cout<<endl;
}

bool chk(int a,int b)
{
    for(int i=a,j=b;i<=n&&j<=n;++i,++j)
        if(pic[i][j]==1)
            return false;
    for(int i=a,j=b;i>=1&&j>=1;--i,--j)
        if(pic[i][j]==1)
            return false;
    for(int i=a,j=b;i>=1&&j<=n;--i,++j)
        if(pic[i][j]==1)
            return false;
    for(int i=a,j=b;i<=n&&j>=1;++i,--j)
        if(pic[i][j]==1)
            return false;
    /*
    for(int i=a;i>=0;--i)
        if(pic[i][b]==1)
            return false;
    for(int i=a;i<=n;++i)
        if(pic[i][b]==1)
            return false;
    for(int i=b;i>=0;--i)
        if(pic[a][i]==1)
            return false;
    for(int i=b;i<=n;++i)
        if(pic[a][i]==1)
            return false;
    */
    return true;
}

void dfs(int row,int idx)
{
    if(idx==n+1)
    {
        cnt++;
        if(cnt<=3)
            put();
        return;
    }
    if(row>n)
        return;
    for(int col=1;col<=n;++col)
    {
        if(!xpy[row+col+n]&&!xmy[row-col+n]&&!vis[col])
        {
            ///pic[row][col]=1;
            ans[idx]=col;
            vis[col]=true;
            xpy[row+col+n]=true;
            xmy[row-col+n]=true;
            dfs(row+1,idx+1);
            ///pic[row][col]=0;
            ans[idx]=0;
            vis[col]=false;
            xpy[row+col+n]=false;
            xmy[row-col+n]=false;
        }
    }
}

int main()
{
    ///memset(pic,0,sizeof(pic));
    memset(vis,0,sizeof(vis));
    memset(xpy,0,sizeof(xpy));
    memset(xmy,0,sizeof(xmy));
    cin>>n;
    dfs(1,1);
    cout<<cnt;
    return 0;
}
