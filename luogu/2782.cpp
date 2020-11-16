#include <bits/stdc++.h>
using namespace std;

const int maxn=1000000;

int n,ans=0;
int tmp[maxn+5],top=0;
struct way
{
    int a,b;
}w[maxn+5];

bool cmp(way a,way b)
{
    return a.a<b.a;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d %d",&w[i].a,&w[i].b);
    sort(w,w+n,cmp);
    ///找最长不下降子序列
    tmp[top]=w[0].b;
    for(int i=1;i<n;++i)
    {
        if(w[i].b>tmp[top])
        {
            top++;
            tmp[top]=w[i].b;
        }
        else
            tmp[lower_bound(tmp,tmp+top,w[i].b)-tmp]=w[i].b;
    }
    printf("%d",top+1);
    return 0;
}
