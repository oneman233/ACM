#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MAX=100000;

ll a,b,tn,n,ans=0;
bool isp[MAX+1];
vector<ll> p,c;

bool isprime(ll num)
{
    if(num==0||num==1)
        return false;
    for(ll i=2;i*i<=num;++i)
        if(num%i==0)
            return false;
    return true;
}

void sieve()
{
    memset(isp,0,sizeof(isp));
    p.clear();
    for(ll i=2;i<=MAX;++i){
        if(!isp[i])
            p.push_back(i);
        for(int j=0;j<p.size();++j){
            if(i*p[j]>MAX)
                break;
            isp[i*p[j]]=true;
            if(i%p[j]==0)
                break;
        }
    }
}

void cut()
{
    if(isprime(n)){
        c.push_back(n);
        return;
    }
    for(int j=0;j<p.size();++j){
        if(n%p[j]==0){
            c.push_back(p[j]);
            while(n%p[j]==0){
                n/=p[j];
            }
            if(n==1)
                break;
        }
    }
    if(isprime(n)){
        c.push_back(n);
        return;
    }
}

void debug()
{
    cout<<n<<endl;
    cout<<endl;
    for(auto i:c)
        cout<<i<<endl;
}

int main()
{
    cin>>a>>b>>n;
    tn=n;
    sieve();
    cut();
    ///debug();
    for(ll i=1;i<(1<<c.size());++i){
        int cnt=0;
        ll mul=1;
        for(ll j=0;j<c.size();++j){
            if(i&(1<<j)){
                cnt++;
                mul*=c[j];
            }
        }
        if(cnt&1)
            ans+=b/mul-(a-1)/mul;
        else
            ans-=b/mul-(a-1)/mul;
    }
    if(tn>=a&&tn<=b&&ans>0)
        ans--;
    cout<<ans;
    return 0;
}
/*
16532303225886 16532303225888 16532303225888
*/
