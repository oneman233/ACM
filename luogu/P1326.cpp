#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,t,n;
    while(cin>>s>>t>>n){
        int big,sml;
        if(s<n)
            big=3*s+n-1-s+0;
        else{
            if(s-(n-1)>t)
                big=3*(n-1)+3;
            else if(s-(n-1)==t)
                big=3*(n-1)+1;
            else
                big=3*(n-1)+0;
        }
        if(t<n)
            sml=0*t+n-1-t+3;
        else{
            if(t-(n-1)>s)
                sml=0*(n-1)+0;
            else if(t-(n-1)==s)
                sml=0*(n-1)+1;
            else
                sml=0*(n-1)+3;
        }
        if(t>s)
            sml=min(sml,1*(n-1)+0);
        else if(t==s)
            sml=min(sml,1*(n-1)+1);
        else
            sml=min(sml,1*(n-1)+3);
        if(s>t)
            big=max(big,1*(n-1)+3);
        else if(s==t)
            big=max(big,1*(n-1)+1);
        else
            big=max(big,1*(n-1)+0);
        cout<<big<<' '<<sml<<endl;
    }
    return 0;
}
