#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[5];
    for(int i=0;i<n;i++)
        cin>>num[i];
    int cha=num[1]-num[0];
    for(int i=1;i<n;i++)
        num[i]=num[i-1]+cha;
    for(int i=0;i<n;i++)
    {
        cout<<num[i];
        if(i!=(n-1))
            cout<<" ";
    }
    return 0;
}
