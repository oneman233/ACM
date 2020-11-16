#include <bits/stdc++.h>

using namespace std;

unsigned long long f(int k)
{
    if(k==1)
        return 1;
    else
        return f(k-1)*(4*k-2)/(k+1);//卡特兰数的递推公式
}

int main()
{
    int k;
    cin>>k;
    cout<<f(k)<<" "<<k+1;//2k个点最少切成k+1块
    return 0;
}
