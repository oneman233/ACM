#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;
const int inf=INT_MAX;

int n,k;
struct st
{
    int v,p;
}a[maxn+5];
deque<st> d;
vector<int> mi,ma;
int tma=-inf,tmi=inf,tmai,tmii;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

int main()
{
    n=read();
    k=read();
    for(int i=0;i<n;++i)
    {
        a[i].v=read();
        a[i].p=i;
    }
    for(int i=0;i<min(n,k);++i){
        d.push_back(a[i]);
        if(a[i].v<=tmi){
            tmi=a[i].v;
            tmii=a[i].p;
        }
        if(a[i].v>=tma){
            tma=a[i].v;
            tmai=a[i].p;
        }
    }
    mi.push_back(tmi);
    ma.push_back(tma);
    int i=k;
    while(i<n){
        ///update max values
        if(a[i].v<=tmi){
            tmi=a[i].v;
            tmii=a[i].p;
        }
        if(a[i].v>=tma){
            tma=a[i].v;
            tmai=a[i].p;
        }
        d.push_back(a[i]);
        d.pop_front();
        ///if max values were popped
        if(tmii<i-k+1){
            tmi=inf;
            for(int i=0;i<d.size();++i){
                if(d[i].v<=tmi){
                    tmi=d[i].v;
                    tmii=d[i].p;
                }
            }
        }
        if(tmai<i-k+1){
            tma=-inf;
            for(int i=0;i<d.size();++i){
                if(d[i].v>=tma){
                    tma=d[i].v;
                    tmai=d[i].p;
                }
            }
        }
        mi.push_back(tmi);
        ma.push_back(tma);
        ++i;
    }
    for(int i=0;i<mi.size();++i)
        cout<<mi[i]<<" ";
    cout<<endl;
    for(int i=0;i<ma.size();++i)
        cout<<ma[i]<<" ";
    return 0;
}
