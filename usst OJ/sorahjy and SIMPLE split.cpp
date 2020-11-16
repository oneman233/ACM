#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,temp;
    int ans=0;
    set<long long> s;
    cin>>n;
    temp=n;
    long long a[105];
    for(int i=0;i<n;i++)
        cin>>a[i];
    while(temp!=0)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1)
            {
                if(s.count(a[i])==0)
                {
                    s.insert(a[i]);
                    a[i]=-1;
                    temp--;
                }
                else;
            }
        }
        s.clear();
        ans++;
    }

    cout<<ans;
    return 0;
}
