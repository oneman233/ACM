#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> l;
    list<int>::iterator it;
    int num;
    int m,n;
    int ans=0;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        bool lock=true;
        cin>>num;
        for(it=l.begin();it!=l.end();it++)
        {
            if(*it==num)
            {
                lock=false;
                break;
            }
        }
        if(lock)
        {
            l.push_back(num);
            ans++;
            if(l.size()>m)
                l.pop_front();
        }
    }
    cout<<ans;
    return 0;
}
