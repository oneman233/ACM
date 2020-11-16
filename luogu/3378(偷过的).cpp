#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > pq;
    int n;
    cin>>n;
    while(n--)
    {
        int k,x;
        cin>>k;
        if(k==1)
        {
            cin>>x;
            pq.push(x);
        }
        else if(k==2)
            cout<<pq.top()<<endl;
        else if(k==3)
            pq.pop();
    }
    return 0;
}
