#include <bits/stdc++.h>
using namespace std;

int wei(int num)
{
    int ans=0;
    while(num)
    {
        ans+=num%10;
        num/=10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        if(i+wei(i)==n)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}
