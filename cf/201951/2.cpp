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
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        map<char,int> m;
        cin>>s;
        int n=s.length();
        fo(i,0,n)
            m[s[i]]++;
        string ans="",ans2="";
        for(char c='y';c>='a';c-=2)
            ans.append(m[c],c);
        for(char c='z';c>='b';c-=2)
            ans.append(m[c],c);
        for(char c='a';c<='y';c+=2)
            ans2.append(m[c],c);
        for(char c='b';c<='z';c+=2)
            ans2.append(m[c],c);
        bool can=true,can2=true;
        fo(i,0,n-1)
            if(ans[i]==ans[i+1]-1||ans[i]==ans[i+1]+1){
                can=false;break;
            }
        fo(i,0,n-1)
            if(ans2[i]==ans2[i+1]-1||ans2[i]==ans2[i+1]+1){
                can2=false;break;
            }
        if(!can2&&!can)
            cout<<"No answer"<<endl;
        else
        {
            if(can){
                cout<<ans<<endl;continue;
            }
            if(can2){
                cout<<ans2<<endl;continue;
            }
        }
    }
    return 0;
}
