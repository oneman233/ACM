#include <bits/stdc++.h>

using namespace std;

string f(string a)
{
    if(a=="0")
        return "1";
    if(a=="1")
        return "0";
    int ans=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='0'||a[i]=='6'||a[i]=='9'||a[i]=='4')
            ans+=1;
        else if(a[i]=='8')
            ans+=2;
        else;
    }
    string out=to_string(ans);
    return out;
}

int main()
{
    int t;
    unsigned long long k;
    string in;
    cin>>t;
    while(t--)
    {
        cin>>in>>k;
        while(k!=0)
        {
            in=f(in);
            k--;
            if(in=="0"||in=="1")
                break;
        }
        if(in=="0")
        {
            if(k%2==0)
                cout<<"0"<<endl;
            else
                cout<<"1"<<endl;
        }
        else if(in=="1")
        {
            if(k%2==0)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else
            cout<<in<<endl;
    }
    return 0;
}
