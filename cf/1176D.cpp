#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define sci(a) scanf("%d",&a)
using namespace std;
const int maxn=2800000;

vector<int> p,as;
bool vis[maxn+10];
int n,tp;
map<int,int> m;

void get()
{
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=maxn;++i){
        if(!vis[i])
            p.pb(i);
        for(int j=0;j<p.size();++j){
            if(i*p[j]>maxn)
                break;
            vis[i*p[j]]=true;
            if(i%p[j]==0)
                break;
        }
    }
}

int bigfac(int x)
{
    for(int i=0;i<p.size();++i)
        if(x%p[i]==0)
            return x/p[i];
}

bool isp(int x)
{
    if(!vis[x])
        return true;
    else
        return false;
}

void work()
{
    for(auto i=m.rbegin();i!=m.rend();++i){
        if(i->second==0)
            continue;
        if(!isp(i->first)){
            while(m[i->first]!=0){
                m[i->first]--;
                m[bigfac(i->first)]--;
                as.pb(i->first);
            }
        }
    }
    for(auto i=m.begin();i!=m.end();++i){
        if(i->second==0)
            continue;
        if(isp(i->first)){
            while(m[i->first]!=0){
                m[i->first]--;
                m[p[(i->first)-1]]--;
                as.pb(i->first);
            }
        }
    }
}

void out()
{
    for(auto i:as)
        cout<<i<<" ";
}

int main()
{
    get();
    sci(n);
    for(int i=0;i<2*n;++i){
        sci(tp);
        m[tp]++;
    }
    work();
    out();
    return 0;
}
