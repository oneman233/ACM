#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
map<int,int>::iterator it;
int n,read;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>read;
        m[read]++;
    }
    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second>=3)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    vector<int> big,sml;
    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second!=0)
        {
            sml.push_back(it->first);
            it->second--;
        }
    }
    for(it=m.begin();it!=m.end();++it)
    {
        if(it->second!=0)
        {
            big.insert(big.begin(),it->first);
            it->second--;
        }
    }
    cout<<sml.size()<<endl;
    for(int i=0;i<sml.size();++i)
    {
        cout<<sml[i];
        if(i!=sml.size()-1)
            cout<<" ";
    }

    cout<<endl;

    cout<<big.size()<<endl;
    for(int i=0;i<big.size();++i)
    {
        cout<<big[i];
        if(i!=big.size()-1)
            cout<<" ";
    }
    return 0;
}
