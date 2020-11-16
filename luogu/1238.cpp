#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[20][20];
int sx,sy,ex,ey;
int x[100000],y[100000];
bool can=false;

void dfs(int i,int j,int idx)
{
    if(i<1||i>n||j<1||j>m||a[i][j]==0)
        return;
    if(i==ex&&j==ey)
    {
        ///cout<<i<<" "<<j<<endl;
        x[idx]=i,y[idx]=j;
        for(int i=0;i<=idx;++i)
        {
            printf("(%d,%d)",x[i],y[i]);
            if(i!=idx)
                printf("->");
        }
        printf("\n");
        x[idx]=y[idx]=0;
        can=true;
        return;
    }
    a[i][j]=0;
    x[idx]=i;
    y[idx]=j;
    dfs(i,j-1,idx+1);
    dfs(i-1,j,idx+1);
    dfs(i,j+1,idx+1);
    dfs(i+1,j,idx+1);
    a[i][j]=1;
    x[idx]=0;
    y[idx]=0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&sx,&sy);
    scanf("%d %d",&ex,&ey);
    dfs(sx,sy,0);
    if(!can)
        printf("-1");
    return 0;
}
