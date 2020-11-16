#include <bits/stdc++.h>
using namespace std;

int n,tmp,big=0;
int cnt[1000005],ans[10005];

void work(int x)
{
    for(int i=1;i*i<=x;++i){
        if(x%i==0){
            cnt[i]++;
            if(i!=x/i)
                cnt[x/i]++;
        }
    }
}

int main()
{
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        big=max(big,tmp);
        work(tmp);
    }
    int pre=0;
    for(int i=big;i>=1;--i){
        if(cnt[i]!=0&&cnt[i]-pre>0){
            for(int j=cnt[i];j>=pre+1;--j){
                if(ans[j]!=0)
                    break;
                else
                    ans[j]=i;
            }
            pre=cnt[i];
        }
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<'\n';
    return 0;
}
