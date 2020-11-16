#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

const int MAX=105;
const int INF=1e+6;

int n;//节点数
int way[MAX][MAX],par[MAX],low[MAX];
//储存矩阵、父节点最低消耗
bool vis[MAX];//是否被访问
vector<int> out;
long long ans=0;
//储存输出
int make,cost;
//储存修哪个节点和当前最低消耗

int main()
{
    scanf("%d",&n);
    _rep(i,1,n)
    {
        _rep(j,1,n)
        {
            scanf("%d",&way[i][j]);
        }
    }
    _rep(i,1,n)
    {
        vis[i]=false;
        low[i]=INF;
    }
    low[1]=0;
    //第一步必修一号节点，到那儿去把一号节点设置为已访问
    par[1]=1;
    //起点的父节点是自己
    _rep(i,1,n)
    {
        cost=INF;
        _rep(j,1,n)
        {
            if(!vis[j]&&low[j]<cost)
            {
                cost=low[j];
                make=j;
            }
        }
        vis[make]=true;
        ans+=cost;
        if(cost)//如果消耗不为0，代表新修的路，按照字典序储存
        {
            out.push_back(min(make,par[make]));
            out.push_back(max(make,par[make]));
        }
        _rep(j,1,n)
        {
            if(!vis[j]&&way[make][j]<low[j])//考虑的是从j修到make的路径
            {
                low[j]=way[make][j];
                par[j]=make;
            }
        }
    }
    printf("%d",out.size()/2);
    if(!out.empty())
    {
        for(int i=0;i<=out.size()-1;i+=2)
            printf("\n%d %d",out[i],out[i+1]);
    }
    printf("\n%lld",ans);
}
