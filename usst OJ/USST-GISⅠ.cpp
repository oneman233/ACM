#include <bits/stdc++.h>
using namespace std;

bool can=false;
int n,m,t;
char p[100][100];

bool chk(int i,int j)
{
    if(i<1||i>n||j<1||j>m||p[i][j]=='X')
        return false;
    return true;
}

void dfs(int i,int j,int step)
{
    if(p[i][j]=='D'&&step==t){
        can=true;
        return;
    }
    if(can||step>t)
        return;
    char tmp=p[i][j];
    p[i][j]='X';
    if(chk(i+1,j))
        dfs(i+1,j,step+1);
    if(chk(i-1,j))
        dfs(i-1,j,step+1);
    if(chk(i,j+1))
        dfs(i,j+1,step+1);
    if(chk(i,j-1))
        dfs(i,j-1,step+1);
    p[i][j]=tmp;
}

int main()
{
    cin>>n>>m>>t;
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>p[i][j];
            if(p[i][j]=='.')
                cnt++;
        }
    }
    if(t>cnt+1){
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(p[i][j]=='S'){
                p[i][j]=='.';
                dfs(i,j,0);
                break;
            }
        }
    }
    if(can)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
/*
8 8 100
S.......
........
........
........
........
........
........
.......D
*/
