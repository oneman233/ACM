#include <bits/stdc++.h>
using namespace std;
const int maxn=5000005;

int tr[maxn][2],tot=1,cnt[maxn],ise[maxn];
int n,m,l,s[maxn];

void add(int s[],int len)
{
    int p=1;
    for(int i=0;i<len;++i){
        if(tr[p][s[i]]==0)
            tr[p][s[i]]=++tot;
        p=tr[p][s[i]];
        cnt[p]++;
    }
    ise[p]++;
}

int ask(int s[],int len)
{
    int p=1;
    int ans=0;
    for(int i=0;i<len;++i){
        ans+=ise[p];
        ///check the prefix of s
        if(tr[p][s[i]]==0)
            return ans;
        p=tr[p][s[i]];
    }
    ans+=cnt[p];
    ///check those who have prefix s
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&l);
        for(int i=0;i<l;++i)
            scanf("%d",&s[i]);
        add(s,l);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&l);
        for(int i=0;i<l;++i)
            scanf("%d",&s[i]);
        printf("%d\n",ask(s,l));
    }
    return 0;
}
