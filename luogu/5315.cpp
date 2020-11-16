#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,g;
    cin>>n>>l>>g;
    while(n--)
    {
        int w,h;
        cin>>w>>h;
        while(w>g||h>g)
        {
            w/=2;
            h/=2;
        }
        if(w<l||h<l)
            cout<<"Too Young";
        else if(w>=l&&h>=l&&w!=h)
            cout<<"Too Simple";
        else if(w>=l&&h>=l&&w==h)
            cout<<"Sometimes Naive";
        if(n!=0)
            cout<<endl;
    }
    return 0;
}
