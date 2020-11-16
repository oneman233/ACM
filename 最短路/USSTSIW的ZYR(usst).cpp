#include <bits/stdc++.h>
using namespace std;
const int MAX=3000;
const int inf=0x3f3f3f3f;

int t,s,d,st;
int dt[MAX+5];
int x,y,z;
int p[MAX+5][MAX+5];
int dis[MAX+5];

void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    bool vis[MAX+5];
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    for(int i=0;i<=MAX;++i)
        dis[i]=p[s][i];
    int cnt=MAX;
    while(cnt--){
        int sml=inf;
        for(int i=0;i<=MAX;++i){
            if(!vis[i]&&dis[i]<sml){
                sml=dis[i];
                s=i;
            }
        }
        vis[s]=true;
        for(int i=0;i<=MAX;++i)
            dis[i]=min(dis[i],dis[s]+p[s][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(p,0x3f,sizeof(p));
    for(int i=1;i<=MAX;++i)
        p[i][i]=0;
    cin>>t>>s>>d;
    while(t--){
        cin>>x>>y>>z;
        p[x][y]=p[y][x]=z;
    }
    while(s--){
        cin>>st;
        p[0][st]=p[st][0]=0;
    }
    for(int i=0;i<d;++i)
        cin>>dt[i];
    dij(0);
    int ans=inf;
    /*
    for(int i=1;i<=10;++i)
        cout<<dis[i]<<endl;
    */
    for(int i=0;i<d;++i)
        ans=min(ans,dis[dt[i]]);
    cout<<ans;
    return 0;
}
/*
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
*/
