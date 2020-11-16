#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
typedef long long ll;

string s;
int cnt[maxn];

int main()
{
    memset(cnt,0,sizeof(cnt));
    cin>>s;
    for(int i=0;i<s.length();++i){
        if(s[i]=='A'){
            for(int j=i+2;j<s.length();++j)
                if(s[j]=='Q')
                    cnt[i]++;
        }
    }
    ll ans=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='Q'){
            for(int j=i+2;j<s.length();++j)
                if(s[j]=='A')
                    ans+=cnt[j];
        }
    }
    printf("%lld",ans);
    return 0;
}
