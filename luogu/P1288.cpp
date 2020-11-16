#include <bits/stdc++.h>
using namespace std;

int n,a[25];

int l(int i){if(i==1) return n; return i-1;}
int r(int i){if(i==n) return 1; return i+1;}

int main()
{
    cin>>n;
    if(n==1){
        cout<<"NO";
        return 0;
    }
    /*
    if(n==2){
        int x,y;
        cin>>x>>y;
        if(x==0&&y==0){
            cout<<"NO";
        }
        else{
            cout<<"YES";
        }
        return 0;
    }
    */
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bool can=false;
    int cnt=0,i=1;
    do{
        if(a[i]==0)
            break;
        else
            cnt++,
            i=r(i);
    }while(i!=1);
    if(cnt&1)
        can=true;
    cnt=0,i=n;
    do{
        if(a[i]==0)
            break;
        else
            cnt++,
            i=l(i);
    }while(i!=n);
    if(cnt&1)
        can=true;
    if(can)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
