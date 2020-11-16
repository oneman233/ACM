#include <bits/stdc++.h>

using namespace std;

int main()
{
    int out=0;
    int guke,shichang,xiuxi;
    int s_tou,s_wei,x_tou,x_wei;
    cin>>guke>>shichang>>xiuxi;
    if(guke==0)
        out=shichang/xiuxi;
    for(int i=1;i<=guke;i++)
    {
        if(i==1)
        {
            cin>>s_tou>>s_wei;
            s_wei=s_tou+s_wei;
            out+=s_tou/xiuxi;
        }
        else if(i==guke)
        {
            cin>>x_tou>>x_wei;
            x_wei=x_tou+x_wei;
            out+=(x_tou-s_wei)/xiuxi;
            out+=(shichang-x_wei)/xiuxi;
        }
        else
        {
            cin>>x_tou>>x_wei;
            x_wei=x_tou+x_wei;
            out+=(x_tou-s_wei)/xiuxi;
            s_tou=x_tou;
            s_wei=x_wei;
        }
    }
    cout<<out;
    return 0;
}
