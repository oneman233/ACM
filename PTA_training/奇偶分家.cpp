#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int ji=0,ou=0;
    int read;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>read;
        if(read&1)
            ji++;
        else
            ou++;
    }
    cout<<ji<<" "<<ou;
    return 0;
}
