#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    unsigned long long s,a,b,c;
    //һ��s��Ǯ��c��Ǯһ����ÿ��a����b��
    cin>>T;
    while(T--)
    {
        cin>>s>>a>>b>>c;
        if(c==0)
            cout<<"INF";
        else if(s<c)
            cout<<"0";
        else
        {
            cout<<s/c+(s/c/a*b);
        }
        if(T!=0)
            cout<<"\n";
    }
    return 0;
}
