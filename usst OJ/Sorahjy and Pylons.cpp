#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long int num,big=0;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(num>big)
            big=num;
    }
    cout<<big;
    return 0;
}
