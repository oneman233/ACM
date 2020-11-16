#include <bits/stdc++.h>
using namespace std;

int main()
{
    int j;
    cin>>j;
    if(j<4)
        cout<<0;
    else
        cout<<(j-1)*(j-2)*(j-3)/6;
    return 0;
}
