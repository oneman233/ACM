#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n;
struct edge
{
    int idx;
    int h,l,r;
}e[maxn];
int a1[maxn],a2[maxn];

bool cmp(edge a,edge b)
{
    if(a.h!=b.h)
        return a.h>b.h;
    else
        return a.idx<b.idx;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>e[i].h>>e[i].l>>e[i].r;
        e[i].idx=i+1;
    }
    sort(e,e+n,cmp);
    for(int i=0;i<n;++i){
        int j;
        j=0;
        while(j<n){
            if(e[j].h<e[i].h&&e[j].l<e[i].l&&e[j].r>e[i].l)
                break;
            j++;
        }
        if(j!=n)
            a1[e[i].idx]=e[j].idx;
        else
            a1[e[i].idx]=0;
        j=0;
        while(j<n){
            if(e[j].h<e[i].h&&e[j].l<e[i].r&&e[j].r>e[i].r)
                break;
            j++;
        }
        if(j!=n)
            a2[e[i].idx]=e[j].idx;
        else
            a2[e[i].idx]=0;
    }
    for(int i=1;i<=n;++i)
        cout<<a1[i]<<" "<<a2[i]<<endl;
    return 0;
}
