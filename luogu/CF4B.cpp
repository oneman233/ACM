#include <bits/stdc++.h>
using namespace std;

int d,sm;
int mn[5000],mx[5000],as[5000];

int main()
{
    cin>>d>>sm;
    int mxct=0,mnct=0;
    for(int i=1;i<=d;++i)
        cin>>mn[i]>>mx[i],mnct+=mn[i],mxct+=mx[i];
    if(mxct<sm||mnct>sm)
        cout<<"NO";
    else{
        for(int i=1;i<=d;++i)
            as[i]=mx[i];
        int ix=1;
        while(mxct>sm){
            int tp=as[ix]-mn[ix];
            if(tp>=mxct-sm){
                as[ix]-=mxct-sm;
                mxct=sm;
                break;
            }
            else{
                mxct-=tp;
                as[ix]=mn[ix];
            }
            ix++;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=d;++i)
            cout<<as[i]<<" ";
    }
    return 0;
}
