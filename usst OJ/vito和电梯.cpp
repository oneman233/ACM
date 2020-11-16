#include <bits/stdc++.h>

using namespace std;

int main()
//n方复杂度
//人们不去一楼
{
    int n;
    long long ceng,bumanyi=100000000;
    long long x,y;
    long long temp;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            temp=(n-i+1)*(n-i)*x/2+(j-1)*(j-2)*x/2+(i-j+1)*(i-j)*y/2;
            //必须向上的一堆人
            //从一楼到j楼向上的一批人
            //从i楼到j楼向下的一批人
            if(temp<bumanyi)
            {
                bumanyi=temp;
                ceng=i;
            }
        }
    }
    cout<<ceng<<" "<<bumanyi;
    return 0;
}
