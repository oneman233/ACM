#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;

int n,k;
int maxa=INT_MIN,maxp=-1;
struct gift
{
    int a,p;
}g[maxn+5];
deque<gift> dq;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%d",&g[i].a);
        g[i].p=i;
    }
    for(int i=1;i<=k;++i)
        dq.push_back(g[i]);
    for(int i=0;i<k;++i)
    {
        if(dq[i].a>maxa)
        {
            maxa=dq[i].a;
            maxp=dq[i].p;
        }
    }
    printf("%d %d",maxa,maxp);
    for(int i=k+1;i<=n;++i)
    {
        dq.push_back(g[i]);
        if(dq.front().p==maxp)
        {
            dq.pop_front();
            maxa=INT_MIN,maxp=-1;
            for(int i=0;i<k;++i)
            {
                if(dq[i].a>maxa)
                {
                    maxa=dq[i].a;
                    maxp=dq[i].p;
                }
            }
        }
        else
        {
            dq.pop_front();
            if(dq.back().a>maxa)
            {
                maxa=dq.back().a;
                maxp=dq.back().p;
            }
        }
        printf("\n%d %d",maxa,maxp);
    }
    return 0;
}
