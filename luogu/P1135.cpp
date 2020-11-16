#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define po() pop_front()
using namespace std;

int n,a,b;
int k[2005],ans[2005];
bool vis[2005];

void bfs()
{
    memset(vis,0,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    deque<int> dq;
    dq.pb(a);
    ans[a]=0;
    if(a==b){
        cout<<0;
        return;
    }
    while(!dq.empty()){
        int f=dq.front();
        if(vis[f]){
            dq.po();
            continue;
        }
        if(f+k[f]<=n&&!vis[f+k[f]]){
            ans[f+k[f]]=min(ans[f+k[f]],ans[f]+1);
            dq.pb(f+k[f]);
        }
        if(f-k[f]>=1&&!vis[f-k[f]]){
            ans[f-k[f]]=min(ans[f-k[f]],ans[f]+1);
            dq.pb(f-k[f]);
        }
        vis[f]=true;
        dq.po();
    }
    if(ans[b]!=0x3f3f3f3f)
        cout<<ans[b];
    else
        cout<<-1;
}

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)
        cin>>k[i];
    bfs();
    return 0;
}
