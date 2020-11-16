#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        pq.push(tmp);
    }
    long long ans=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans;
    return 0;
}
