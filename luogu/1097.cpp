#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<long long,int> m;
    map<long long,int>::iterator it;
    int n;
    cin>>n;
    long long tmp;
    while(n--)
    {
        cin>>tmp;
        m[tmp]++;
    }
    for(it=m.begin();it!=m.end();++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    ///system("pause");
    return 0;
}
