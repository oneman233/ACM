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
const int maxn=300000;
typedef long long ll;

int t,dp[1001][1001];
string s;

inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

inline void sw(char &a,char &b)
{
    char c=a;
    a=b;
    b=c;
}

int main()
{
    t=read();
    while(t--){
        int ans=0;
        cin>>s;
        map<char,int> m;
        int len=s.length();
        fo(i,0,len)
            m[s[i]]++;
        int cnt=0;
        for(char i='a';i<='z';++i){
            if(m[i]&1){
                cnt++;
                if(cnt>=2)
                    break;
            }
        }
        if(cnt>=2){
            cout<<"Impossible"<<endl;
            continue;
        }
        else{
            /*
            memset(dp,0,sizeof(dp));
            string ts="";
            for(int i=len-1;i>=0;--i)
                ts.append(1,s[i]);
            for(int i=1;i<=len;++i){
                for(int j=1;j<=len;++j){
                    if(s[i-1]==ts[j-1])
                        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                    else
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
            cout<<len-dp[len][len]<<endl;
            */
            for(int i=0;i<=len/2;++i){
                if(s[i]==s[len-i-1])
                    continue;
                for(int j=len-i-2;j>=0;--j){
                    if(j==i){
                        for(int k=j;k<=len/2-1;++k){
                            sw(s[k],s[k+1]);
                            ans++;
                        }
                        break;
                    }
                    if(s[j]==s[i]){
                        for(int k=j;k<=len-i-2;++k){
                            sw(s[k],s[k+1]);
                            ans++;
                        }
                        break;
                    }
                }
                ///cout<<s<<endl;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
