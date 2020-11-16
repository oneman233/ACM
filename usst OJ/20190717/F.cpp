#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;

int n,xx,yy;
int limit[maxn];
int dep[maxn];
struct edge
{
    int y,to;
}e[maxn];
int head[maxn],tot=0;
vector<int> dep_idx[maxn];
map<int,int> limit_cnt;
priority_queue<int,vector<int>,greater<int> > pq;
bool vis[maxn];

void add(int x,int y)
{
    e[++tot].y=y;
    e[tot].to=head[x];
    head[x]=tot;
}

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    for(int i=head[x];i;i=e[i].to)
        if(e[i].y!=f)
            dfs(e[i].y,x);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&limit[i]);
    for(int i=1;i<=n-1;++i){
        scanf("%d %d",&xx,&yy);
        add(xx,yy);
    }
    dfs(1,1);
    for(int i=1;i<=n;++i)
        dep_idx[dep[i]].push_back(i);
    for(int i=1;i<=n;++i)
        limit_cnt[limit[i]]++;
    pq.push(1);
    int flag=1,level=2;
    while(!pq.empty()){
        int tmp=pq.top();
        if(!vis[pq.top()]){
            printf("%d\n",pq.top());
            pq.pop();
        }
        else{
            pq.pop();
            continue;
        }
        vis[tmp]=1;
        limit_cnt[limit[tmp]]--;
        while(limit_cnt[flag]==0&&flag<=n) flag++;
        while(level<=flag){
            for(int i=0;i<dep_idx[level].size();++i){
                if(!vis[dep_idx[level][i]])
                    pq.push(dep_idx[level][i]);
            }
            level++;
        }
    }
    return 0;
}
