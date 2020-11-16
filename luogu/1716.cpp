#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll tmp;
deque<ll> dq;

int main()
{
    cin>>n;
    while(n--){
        cin>>tmp;
        dq.push_back(tmp);
    }
    sort(dq.begin(),dq.end());
    while(dq.size()>1){
        cout<<dq.back()<<endl;
        dq.pop_back();
        cout<<dq.front()<<endl;
        dq.pop_front();
    }
    if(!dq.empty())
        cout<<dq.front()<<endl;
    return 0;
}
