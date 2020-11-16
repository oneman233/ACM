#include <bits/stdc++.h>
using namespace std;

int t,n;
int sex[10005];
double h[10005];

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>sex[i];
        for(int i=1;i<=n;++i)
            cin>>h[i];
        vector<double> man,woman;
        for(int i=1;i<=n;++i)
            if(sex[i]==1)
                man.push_back(h[i]);
            else
                woman.push_back(h[i]);
        sort(man.begin(),man.end());
        sort(woman.begin(),woman.end());
        for(int i=0;i<woman.size();++i)
            cout<<woman[i]<<' ';
        cout<<endl;
        for(int i=0;i<man.size();++i)
            cout<<man[i]<<' ';
        cout<<endl;
    }
    return 0;
}
