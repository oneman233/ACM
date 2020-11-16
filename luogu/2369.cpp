#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll tmp;
map<ll,int> ma;

int main()
{
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%lld",&tmp);
        ma[tmp]++;
    }
    auto i=ma.begin();
    while(m){
        for(int j=0;j<min(m,i->second);++j)
            printf("%lld\n",i->first);
        m-=min(m,i->second);
        i++;
    }
    return 0;
}
