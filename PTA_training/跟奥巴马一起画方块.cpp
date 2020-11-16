#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    int hang;
    cin>>n>>c;
    if(n/2.0-n/2>=0.5)
        hang=n/2+1;
    else
        hang=n/2;
    for(int i=0;i<hang;i++)
    {
        for(int j=0;j<n;j++)
            cout<<c;
        if(i!=hang-1)
            cout<<endl;
    }
    return 0;
}
