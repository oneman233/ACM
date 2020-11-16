#include <bits/stdc++.h>
using namespace std;

char c[15][15];
bool vis[15][15];
int cnt[15][15];
int fx,fy,tx,ty;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool chk(int i,int j)
{
    if(i<1||i>10||j<1||j>10||vis[i][j]||c[i][j]=='L')
        return false;
    return true;
}

void bfs()
{
    memset(cnt,0x3f,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    cnt[fx][fy]=0;
    queue<int> qx,qy;
    qx.push(fx);
    qy.push(fy);
    while(!qx.empty()&&!qy.empty()){
        int x=qx.front();
        int y=qy.front();
        vis[x][y]=1;
        for(int i=0;i<4;++i){
            if(chk(x+dx[i],y+dy[i])){
                qx.push(x+dx[i]);
                qy.push(y+dy[i]);
                cnt[x+dx[i]][y+dy[i]]=cnt[x][y]+1;
            }
        }
        qx.pop();
        qy.pop();
    }
    cout<<cnt[tx][ty];
}

int main()
{
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            cin>>c[i][j];
        }
    }
    bfs();
    return 0;
}
