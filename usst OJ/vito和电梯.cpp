#include <bits/stdc++.h>

using namespace std;

int main()
//n�����Ӷ�
//���ǲ�ȥһ¥
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
            //�������ϵ�һ����
            //��һ¥��j¥���ϵ�һ����
            //��i¥��j¥���µ�һ����
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
