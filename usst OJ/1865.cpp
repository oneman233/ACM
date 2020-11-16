#include <bits/stdc++.h>
using namespace std;

bool isprime(int a)
{
    if(a<=1)
        return false;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> prime;
    for(int i=2;i<=1000000;i++)
    {
        if(isprime(i))
            prime.push_back(i);
    }
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        if(l>=1&&l<=m&&r>=1&&r<=m)
        {
            int i,j;
            for(i=0;i<prime.size();i++)
            {
                if(prime[i]>l)
                    break;
            }
            for(j=0;j<prime.size();j++)
            {
                if(prime[j]>r)
                    break;
            }
            cout<<j-i<<endl;
            /*5 7答案有问题*/
        }
        else
            cout<<"Crossing the line"<<endl;
    }
    return 0;
}
