#include <bits/stdc++.h>
using namespace std;

int t,n,a;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int tmp;
        cin>>tmp;
        n--;
        while(n--){
            cin>>a;
            tmp^=a;
        }
        if(tmp!=0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
