#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,I,r;
    int a,b;
    long h,cow[10005];
    cin>>n>>I>>h>>r;
    for(int i=1;i<=n;i++)
        cow[i]=h;//����ţΪ��߸߶�
    for(int i=0;i<r;i++)
    {
        cin>>a>>b;//����a��b
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        for(int j=a+1;j<b;j++)//a��b���е�һ�����Լ�
            cow[j]--;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<cow[i];
        if(i!=n)
            cout<<endl;
    }
    return 0;
}
