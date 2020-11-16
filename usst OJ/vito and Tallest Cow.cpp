#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,I,r;
    int a,b;
    long h,cow[10005];
    cin>>n>>I>>h>>r;
    for(int i=1;i<=n;i++)
        cow[i]=h;//所有牛为最高高度
    for(int i=0;i<r;i++)
    {
        cin>>a>>b;//读入a和b
        if(a>b)
        {
            int temp=a;
            a=b;
            b=temp;
        }
        for(int j=a+1;j<b;j++)//a和b当中的一切数自减
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
