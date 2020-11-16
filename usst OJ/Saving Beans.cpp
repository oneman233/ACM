#include <bits/stdc++.h>
#define ll long long
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

using namespace std;

ll n,m,p;
const int maxn=100005;
ll fac[maxn];

void getfac(ll p)//��õ�nλ�õ����н׳ˣ���pȡ����
{
    fac[0]=1;
    _rep(i,1,p)
    {
        fac[i]=fac[i-1]*i%p;
    }
}

ll qpow(ll a,ll b,ll p)
{
    ll ans=1;
    while(b)
    {
        if(b&1)//������Ѵ��㵽������ȥ
            ans*=a%p;
        a*=a%p;
        b/=2;
    }
    return ans;
}

/*�����ݺͽ׳˶�����Ҫÿһ����pȡ�࣬�˷���ȡ�಻Ӱ�������*/

ll lucas(ll a,ll b,ll p)
{
    ll ans=1;
    while(a&&b)//a��b����Ϊ0ʱ
    {
        ll tempa=a%p;
        ll tempb=b%p;
        if(a<b)
            return 0;
        ans=(ans*fac[a]*qpow(fac[b]*fac[a-b]%p,p-2,p))%p;
        /*
        C(a,b) =a! / ( b! * (a-b)! ) mod p
        ��ʵ������ ( a! / (a-b)!)  * ( b! )^(p-2) mod p
        ����С����
        */
        a/=p;
        b/=p;
    }
    return ans;
}

int main()
/*��������m�����ӷ���n�ò�ͬ�����ϣ�һ���ж����ַ�����*/
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&m,&p);
        getfac(p);
        printf("%lld\n",lucas(n+m,m,p));
    }
    return 0;
}
