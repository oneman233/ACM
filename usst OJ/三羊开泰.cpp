#include <bits/stdc++.h>
using namespace std;
const int m=1000000;
typedef long long ll;

int n[9],ans[m+5];
int read;

ll toll(int l,int r)
{
    ll ans=0,base=1;
    for(int i=r;i>=l;--i){
        ans+=n[i]*base;
        base*=10;
    }
    return ans;
}

int main()
{
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=8;++i)
        n[i]=i+1;
    do{
        for(int jia=1;jia<=7;++jia){
            for(int chu=jia+1;chu<=8;++chu){
                ll a=toll(0,jia-1);
                ll b=toll(jia,chu-1);
                ll c=toll(chu,8);
                if(b%c!=0)
                    continue;
                if(a+b/c<=m)
                    ans[a+b/c]++;
            }
        }
    }while(next_permutation(n,n+9));
    cin>>read;
    cout<<ans[read];
    return 0;
}
