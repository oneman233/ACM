#include <bits/stdc++.h>
using namespace std;

int n,tmp,ans=0;
priority_queue<int,vector<int>,greater<int> > pq;

int main()
{
    cin>>n;
    for(int i=0;i<2*n-1;++i){
        cin>>tmp;
        ans+=tmp;
        pq.push(tmp);
    }
    int c=n;
    int cnt=ans;
    while(c--){
        for(int i=0;i<n;++i){
            int top=pq.top();
            pq.pop();
            pq.push(-1*top);
            cnt-=2*top;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
