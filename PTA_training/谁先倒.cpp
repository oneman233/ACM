#include <bits/stdc++.h>
using namespace std;

int main()
{
    int jia,yi;
    cin>>jia>>yi;
    int n;
    cin>>n;
    int jia_han,jia_hua,yi_han,yi_hua;
    int tjia=0,tyi=0;
    while(n--)
    {
        cin>>jia_han>>jia_hua>>yi_han>>yi_hua;
        if(jia_hua==jia_han+yi_han&&yi_hua!=jia_han+yi_han)
            tjia++;
        if(yi_hua==jia_han+yi_han&&jia_hua!=jia_han+yi_han)
            tyi++;
        if(tjia>jia)
        {
            cout<<"A"<<endl;
            cout<<tyi;
            break;
        }
        if(tyi>yi)
        {
            cout<<"B"<<endl;
            cout<<tjia;
            break;
        }
    }
    return 0;
}
