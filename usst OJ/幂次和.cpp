#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,n;
    while(cin>>a>>n)
    {
        if(n>2)
            cout<<-1<<" "<<-1<<endl;
        else if(n==1)
            cout<<1<<" "<<a+1<<endl;
        else
        {
            bool exit=false;
            for(int b=1;b<=a*a;b++)
            {
                for(int c=a*a;c>b;c--)
                {
                    if(a*a==(c*c-b*b))
                    {
                        cout<<b<<" "<<c<<endl;
                        exit=true;
                        break;
                    }
                }
                if(exit)
                    break;
            }
        }
    }
    return 0;
}
