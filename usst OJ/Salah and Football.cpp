#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1000];
    memset(a,0,sizeof(a));
    a[4]=1;
    a[5]=4;
    for(int i=6;i<=100;++i){
        a[i]=a[i-1]+(i-2)*(i-3)/2;
    }
    while(cin>>n){
        cout<<a[n]<<endl;
    }
    return 0;
}
