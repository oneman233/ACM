#include <iostream>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define sci(a) scanf("%d",&a)
#define pri(a) printf("%d",a)
using namespace std;

int main()
{
    int n;
    int pr[105];
    sci(n);
    _for(i,0,n)
        sci(pr[i]);
    bool hard=false;
    _for(i,0,n)
    {
        if(pr[i]==1)
        {
            hard=true;
            break;
        }
    }
    if(hard)
    {
        cout<<"hard";
    }
    else
    {
        cout<<"easy";
    }
    return 0;
}
