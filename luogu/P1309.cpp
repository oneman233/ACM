#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;

int n,r,q;
struct people
{
    int s,val,ix;
    bool operator < (people p)
    {
        if(s!=p.s)
            return s<p.s;
        else
            return ix>p.ix;
    }
}p[maxn],win[maxn],lose[maxn];

bool cmp(people a,people b)
{
   if(a.s!=b.s)
        return a.s>b.s;
    else
        return a.ix<b.ix;
}

void MS()
{
    int tot=1;
    for(int i=1;i<=2*n;i+=2){
        if(p[i].val>p[i+1].val){
            p[i].s+=1;
            win[tot]=p[i];
            lose[tot]=p[i+1];
            tot++;
        }
        else if(p[i].val<p[i+1].val){
            p[i+1].s+=1;
            win[tot]=p[i+1];
            lose[tot]=p[i];
            tot++;
        }
    }
    int i=1,j=1,k=1;
    while(i<=tot&&j<=tot){
        if(win[i]<lose[j]){
            p[k]=lose[j];
            j++;
        }
        else{
            p[k]=win[i];
            i++;
        }
        k++;
    }
    while(i<=tot){
        p[k]=win[i];
        i++;
        k++;
    }
    while(j<=tot){
        p[k]=lose[j];
        j++;
        k++;
    }
}

int main()
{
    scanf("%d%d%d",&n,&r,&q);
    for(int i=1;i<=2*n;++i){
        scanf("%d",&p[i].s);
        p[i].ix=i;
    }
    for(int i=1;i<=2*n;++i)
        scanf("%d",&p[i].val);
    sort(p+1,p+1+2*n,cmp);
    while(r--)
        MS();
    printf("%d",p[q].ix);
    return 0;
}
