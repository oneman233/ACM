#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    int a,b,c,d,e,f;
    int i1,i2,i3,i5,i10,i20;
    cin>>a>>b>>c>>d>>e>>f;
    for(i1=0;i1<=a;i1++)
    {
        for(i2=0;i2<=b;i2++)
        {
            for(i3=0;i3<=c;i3++)
            {
                for(i5=0;i5<=d;i5++)
                {
                    for(i10=0;i10<=e;i10++)
                    {
                        for(i20=0;i20<=f;i20++)
                        {
                            s.insert(i1+2*i2+3*i3+5*i5+10*i10+20*i20);
                        }
                    }
                }
            }
        }
    }
    cout<<s.size()-1;
    return 0;
}
