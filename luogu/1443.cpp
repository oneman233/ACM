#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
    point(int xx,int yy):x(xx),y(yy){}
    point():x(0),y(0){}
}p;
int n,m,dis[505][505];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

bool ok(point p)
{
    if(p.x<1||p.x>n||p.y<1||p.y>m||dis[p.x][p.y]!=-1)
        return false;
    return true;
}

void bfs()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            dis[i][j]=-1;
    dis[p.x][p.y]=0;
    queue<point> q;
    q.push(p);
    while(!q.empty()){
        for(int i=0;i<8;++i){
            point tp(q.front().x+dx[i],q.front().y+dy[i]);
            if(ok(tp)){
                q.push(tp);
                dis[tp.x][tp.y]=dis[q.front().x][q.front().y]+1;
            }
        }
        q.pop();
    }
}

int main()
{
    cin>>n>>m>>p.x>>p.y;
    bfs();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%-5d",dis[i][j]);
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
