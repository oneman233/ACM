#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w,n,tmp;
    int ans=0;
    deque<int> g;
    cin>>w>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        g.push_back(tmp);
    }
    sort(g.begin(),g.end());
    while(!g.empty())
    {
        if(g.size()==1)
        {
            ans++;
            break;
        }
        if(g.back()+g.front()>w)
        {
            g.pop_back();
            ans++;
        }
        else
        {
            g.pop_back();
            g.pop_front();
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
