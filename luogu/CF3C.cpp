#include <bits/stdc++.h>
using namespace std;

char p[4][4];
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
bool awin=false,bwin=false;
bool vis[4][4];

bool ok(int i,int j)
{
    if(i<1||i>3||j<1||j>3||vis[i][j])
        return false;
    return true;
}

void dfs(int i,int j,char c,int cnt,int d)
{
    if(!ok(i,j)||p[i][j]!=c)
        return;
    if(cnt==3&&c=='0'){
        bwin=true;
        return;
    }
    else if(cnt==3&&c=='X'){
        awin=true;
        return;
    }
    vis[i][j]=true;
    if(d==0){
    for(int k=0;k<8;++k)
        dfs(i+dx[k],j+dy[k],c,cnt+1,k+1);
    }
    else
        dfs(i+dx[d-1],j+dy[d-1],c,cnt+1,d);
}

int main()
{
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            cin>>p[i][j];
        }
    }
    int xx=0,zero=0;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            if(p[i][j]=='X') xx++;
            else if(p[i][j]=='0') zero++;
        }
    }
    if(xx!=zero+1&&xx!=zero){
        cout<<"illegal";
        return 0;
    }
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            if(p[i][j]=='0'||p[i][j]=='X'){
                memset(vis,0,sizeof(vis));
                dfs(i,j,p[i][j],1,0);
            }
        }
    }
    if(awin&&bwin||(bwin&&xx==zero+1)||(awin&&xx==zero)){
        cout<<"illegal";
        return 0;
    }
    if(awin&&!bwin)
        cout<<"the first player won";
    else if(bwin&&!awin)
        cout<<"the second player won";
    else{
        if(xx+zero==9)
            cout<<"draw";
        else if(xx==zero+1)
            cout<<"second";
        else if(xx==zero)
            cout<<"first";
    }
    return 0;
}
/*
XXX
X00
X00
*/
