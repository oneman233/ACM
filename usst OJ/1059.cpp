#include <bits/stdc++.h>
using namespace std;

int n;
set<int> s;
int tmp;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        s.insert(tmp);
    }
    cout<<s.size()<<endl;
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();++it)
    {
        cout<<*it<<" ";
    }
    return 0;
}
