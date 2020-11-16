#include <bits/stdc++.h>
using namespace std;

struct way
{
    int p,v;
}hang[3000],lie[3000];
int m,n,k,l,d;
int x,y,p,q;

bool cmp(way a,way b)
{
    return a.v>b.v;
}

int main()
{
    cin>>m>>n>>k>>l>>d;
    for(int i=1;i<=1000;++i)
        hang[i].p=i,lie[i].p=i,hang[i].v=0,lie[i].v=0;
    while(d--){
        cin>>x>>y>>p>>q;
        if(x==p){
            lie[min(y,q)].v++;
        }
        else if(y==q){
            hang[min(x,p)].v++;
        }
    }
    sort(hang,hang+3000,cmp);
    sort(lie,lie+3000,cmp);
    for(int i=0;i<k;++i){
        cout<<hang[i].p;
        if(i!=k-1)
            cout<<" ";
    }
    cout<<endl;
    for(int i=0;i<l;++i){
        cout<<lie[i].p;
        if(i!=l-1)
            cout<<" ";
    }
    return 0;
}
