#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n;
    int a[10005],s[10005];
    while(cin>>n){
        for(int i=0;i<n;++i)
            cin>>a[i];
        int idx=0;
        s[idx]=a[0];
        idx++;
        for(int i=1;i<n;++i){
            if(a[i]>s[idx-1]){
                s[idx]=a[i];
                idx++;
            }
            else if(a[i]<s[idx-1]){
                int pos=upper_bound(s,s+idx,a[i])-s;
                ///first one which is bigger than a[i]
                s[pos]=a[i];
            }
            /*
            for(int i=0;i<idx;++i)
                cout<<s[i]<<" ";
            cout<<endl;
            */
        }
        ///cout<<idx<<endl;
        if(idx>=n-1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*
5
1 3 4 2 5
4
1 4 2 3
*/
