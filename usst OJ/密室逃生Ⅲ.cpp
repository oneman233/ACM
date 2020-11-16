#include <bits/stdc++.h>
using namespace std;

int ha(int i,int j)
{
    return (i+j)%2;
}

int n,m;
int cnt[2];
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
bool can=true;

bool chk(int **a,int i,int j)
{
    if(i<1||i>n||j<1||j>m||a[i][j]==1)
        return false;
    return true;
}

void dfs(int **a,int i,int j)
{
    a[i][j]=1;
    cnt[ha(i,j)]++;
    for(int k=0;k<4;++k){
        if(chk(a,i+x[k],j+y[k]))
            dfs(a,i+x[k],j+y[k]);
    }
}

int main()
{
    memset(cnt,0,sizeof(cnt));
    cin>>n>>m;
    int **a=new int*[n+5];
    for(int i=1;i<=n;++i)
        a[i]=new int[m+5];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0){
                dfs(a,i,j);
                if(cnt[0]!=cnt[1]){
                    can=false;
                    break;
                }
                memset(cnt,0,sizeof(cnt));
            }
    if(can)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
/*
3 2
0 0
0 1
0 1

3 2
0 1
0 0
0 1
*/
