#include <bits/stdc++.h>
using namespace std;

int n;
int a;
int ji=0,ou=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        if(a&1)
            ji++;
        else
            ou++;
    }
    if(ji==0){
        cout<<"Second";
    }
    else{
        if(ji&1){
            cout<<"First";
        }
        else{
            cout<<"First";
        }
    }
    return 0;
}
