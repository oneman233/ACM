#include <bits/stdc++.h>
using namespace std;

int w,n,p;
deque<int> d;

int main()
{
    cin>>w>>n;
    for(int i=0;i<n;++i)
        cin>>p,d.push_back(p);
    sort(d.begin(),d.end());
    int ans=0;
    while(!d.empty()){
        if(d.size()==1){
            ans++;
            break;
        }
        if(d.front()+d.back()>w)
            d.pop_back(),ans++;
        else{
            d.pop_back(),d.pop_front(),ans++;
        }
    }
    cout<<ans;
    return 0;
}
