#include <bits/stdc++.h>
using namespace std;

int n,t;
int a[55];

int main()
{
    cin>>n>>t;
    for(int i=0;i<n;++i)
        cin>>a[i];
    while(t--){
        vector<int> v;
        for(int i=0;i<n;++i)
            if(a[i]==1)
                v.push_back(i);
        for(int i=0;i<v.size();++i){
            if(v[i]==0){
                a[1]=1-a[1];
            }
            else if(v[i]==n-1){
                a[n-2]=1-a[n-2];
            }
            else{
                a[v[i]+1]=1-a[v[i]+1];
                a[v[i]-1]=1-a[v[i]-1];
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<a[i];
        if(i!=n-1)
            cout<<" ";
    }
    return 0;
}
