#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n,m;

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n<m)
            swap(n,m);
        if(n%m==0){
            cout<<"Stan wins"<<endl;
            continue;
        }
        int flag=1;
        while(1){
            if(n>2*m||n%m==0)
                break;
            int tmp=n-m;
            n=m;
            m=tmp;
            flag=1-flag;
        }
        if(flag)
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    return 0;
}
