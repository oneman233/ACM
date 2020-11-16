#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num[10005];
    while(cin>>n)
    {
        bool flag=true;
        for(int i=0;i<n;i++)
            cin>>num[i];
        for(int i=0;i<n-1;i++)
        {
            if(num[i]>num[i+1])
            {
                int temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
                break;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(num[i]>num[i+1])
            {
                cout<<"No"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
    }
    return 0;
}
