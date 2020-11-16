#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000;

ll n;

struct mat
{
    ll m[2][2];
    mat(){memset(m,0,sizeof(m));}
    mat(ll mm[2][2])
    {
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                m[i][j]=mm[i][j];
    }
};
ll ini[2][2]={1,0,0,1};
ll mov[2][2]={3,5,1,3};

mat mul(mat a,mat b)
{
    mat c;
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                c.m[i][j]+=a.m[i][k]*b.m[k][j];
                c.m[i][j]%=mod;
            }
        }
    }
    return c;
}

void qpow()
{
    mat s(ini),tmp(mov);
    n--;
    while(n){
        if(n&1)
            s=mul(s,tmp);
        tmp=mul(tmp,tmp);
        n>>=1;
    }
    printf("%03lld",(2*(s.m[0][0]*3%mod+s.m[0][1]%mod)-1)%mod);
}

int main()
{
    scanf("%lld",&n);
    qpow();
    return 0;
}
///2000000000
