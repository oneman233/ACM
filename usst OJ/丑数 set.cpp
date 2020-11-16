#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    set<LL> s;
    set<LL>::iterator it;
    LL n;
    s.insert(1);
    it=s.begin();
    while(*it<=1000000)
    {
        s.insert(2*(*it));
        s.insert(3*(*it));
        s.insert(5*(*it));
        it++;
    }
    s.erase(1);
    while(cin>>n)
    {
        if(s.count(n))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
