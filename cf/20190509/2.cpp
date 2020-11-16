#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=100000;
typedef long long ll;

int n,a[maxn+5];
int b[maxn+5];

int main()
{
    sci(n);
    re(i,1,n)
        sci(a[i]),b[a[i]]++;
    rre(i,n,1)
    {
        map<int,int> m;
        m.clear();
        re(j,1,100000)
            if(b[j]!=0)
                m[b[j]]++;
        if(m.size()>=3)
        {
            b[a[i]]--;
            continue;
        }
        bool can=false;
        if(m.size()==1)
        {
            if(m.begin()->first==1||m.begin()->second==1){
                cout<<i;
                break;
            }
            else{
                b[a[i]]--;
                continue;
            }
        }
        vector<int> chk;
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();++it)
            chk.pu(it->first);
        if((m[chk[0]]==1&&chk[0]-chk[1]==1)||(m[chk[1]]==1&&chk[1]-chk[0]==1))
            can=true;
        if((m[chk[0]]==1&&chk[0]==1)||(m[chk[1]]==1&&chk[1]==1))
            can=true;
        if(can)
        {
            cout<<i;
            break;
        }
        b[a[i]]--;
    }
    return 0;
}
/*
20
1 1 1 1 1 2 2 2 2 2
3 3 3 3 3 4 4 4 4 4
*/
