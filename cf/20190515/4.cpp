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
const int maxn=200000;
typedef long long ll;

int n;
string str;
stack<int> s;
int ans[maxn+5];

int main()
{
    int flag=0;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;++i){
        if(str[i]=='('){
            ans[i]=flag;
            flag=1-flag;
            s.push(i);
        }
        else{
            ans[i]=ans[s.top()];
            s.pop();
            flag=1-flag;///
        }
    }
    for(int i=0;i<n;++i)
        cout<<ans[i];
    return 0;
}
