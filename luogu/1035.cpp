#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double sum=0.0;
    int temp=1;
    while(true)
    {
        sum+=1.0/temp;
        temp++;
        if(sum>n)
            break;
    }
    cout<<--temp;
    return 0;
}
