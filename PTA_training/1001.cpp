#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,sum;
    bool isnega;
    cin>>a>>b;
    sum=a+b;
    if(sum<0)
        isnega=true;
    else if(sum>0)
        isnega=false;
    else
    {
        cout<<0;
        return 0;
    }
    sum=abs(sum);
    stringstream ss;
    string s;
    ss<<sum;
    ss>>s;
    if(s.length()>=4)
    {
        int pos=s.length()-3;
        while(true)
        {
            s.insert(pos,",");
            pos-=3;
            if(pos<=0)
                break;
        }
    }
    if(isnega)
        cout<<"-"<<s;
    else
        cout<<s;
    return 0;
}
