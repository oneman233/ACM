#include <bits/stdc++.h>

using namespace std;

unsigned long long f(int k)
{
    if(k==1)
        return 1;
    else
        return f(k-1)*(4*k-2)/(k+1);//���������ĵ��ƹ�ʽ
}

int main()
{
    int k;
    cin>>k;
    cout<<f(k)<<" "<<k+1;//2k���������г�k+1��
    return 0;
}
