#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define pub(a) push_back(a)
#define puf(a) push_front(a)
#define pof() pop_front()
#define pob() pop_back()
using namespace std;
typedef long long ll;
const int Max=1000000;

int s,t;
ll sum[Max+10];
deque<int> q;
///储存最长子序列和的下标
///左大右小
ll ans=-1000000;

int main()
{
    cin>>s>>t;
    sum[0]=0;
    _rep(i,1,s)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    ///求前缀和数组
    bool allnega=true;
    _rep(i,0,s-1)
    {
        if(sum[i+1]-sum[i]>0)
        {
            allnega=false;
            break;
        }
    }
    if(allnega)
    ///特判一下全为负数的情况
    {
        _rep(i,0,s-1)
            ans=max(ans,sum[i+1]-sum[i]);
        cout<<ans;
        return 0;
    }
    q.pub(0);
    _rep(i,1,s)
    ///尽量把前缀和较小的位置保存下来
    ///再想办法保存大的位置
    ///保证序列处于递增状态
    {
        while(!q.empty()&&sum[i]<q.front())
            q.pof();///先丢大的
        q.puf(i);
        ///q存入下标是方便计数
        while(!q.empty()&&q.front()-q.back()>t)
            q.pob();///再丢小的
        ans=max(ans,sum[q.front()]-sum[q.back()]);
    }
    cout<<ans;
    return 0;
}
