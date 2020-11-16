#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define elif else if
ll gao(ll a)
{
    if(a==1||a==0||a==2||a==5||a==8)return a;
    if(a==6)return 9;
    if(a==9)return 6;
}
ll f(ll n)
{
    ll rt=0;
    while(n)
    {
        ll tp=n%10;
        if(tp==3||tp==4||tp==7)return -1;
        n=n/10;
        rt=rt*10+gao(tp);
    }
    return rt;
}
inline ll qpow(ll a,ll b,ll P)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%P)
        if(b&1)ans=ans*a%P;
    return ans;
}
inline bool MR(int tc,ll n)
{
    ll u=n-1,t=0;
    while(!(u&1))++t,u>>=1;
    ll x=qpow(tc,u,n);
    if(x==1)return 1;
    for(int i=1;i<=t;++i,x=x*x%n)
        if(x!=n-1&&x!=1&&x*x%n==1)return 0;
    return x==1;
}
mt19937_64 rnd(time(0));

//inline bool isprime(ll n,int S=10)
//{
//    if(n==2)return 1;
//    if(n<2||!(n&1))return 0;
//    while(S--)
//        if(!MR(rnd()%(n-1)+1,n))return 0;
//     return 1;
//
//
//
//}
int isprime(long long n)
{
    double n_sqrt;
    if(n==2 || n==3)
        return 1;
    if(n<=1 || n%6!=1 && n%6!=5)
        return 0;
    n_sqrt=double(sqrt((double)n));
    for(int i=5;i<=n_sqrt;i+=6)
    {
        if(n%(i)==0 | n%(i+2)==0)
            return 0;
    }
    return 1;
}

int main()
{
    ll n;
    cin>>n;
    ll m=0;
    m=f(n);
   // cout<<m<<endl;
    if(m==-1){
        cout<<"no"<<endl;
        return 0;
    }
    if(!isprime(n)){
        cout<<"no"<<endl;
        return 0;
    }
    if(!isprime(m)){
        cout<<"no"<<endl;
        return 0;
    }
    cout<<"yes"<<endl;

    return 0;
}
