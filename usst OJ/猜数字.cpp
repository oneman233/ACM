#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m;
    map<string,int>::iterator it;
    int n;
    cin>>n;
    string name;
    int point;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>name>>point;
        m[name]=point;
        sum+=point;
    }
    sum/=2*n;
    cout<<sum<<" ";
    int ans=1000;
    for(it=m.begin();it!=m.end();it++)
        ans=min(ans,abs(it->second-sum));
    for(it=m.begin();it!=m.end();it++)
    {
        if(abs(it->second-sum)==ans)
        {
            cout<<it->first;
            break;
        }
    }
    return 0;
}
