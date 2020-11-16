#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=100000;

ll n,m,mod;

struct node
{
    ll l,r,v;
    ll ta=0,tm=0;
}a[4*maxn+1];
inline ll ls(ll b){return b*2;}
inline ll rs(ll b){return b*2+1;}
void up(ll b){a[b]=(a[ls(b)]+a[rs(b)])%mod;}
void down(ll b)
{

}

int main()
{

    return 0;
}
