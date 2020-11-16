#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> se;
    for(int i=1;i<=1000;i++)
    {
        string s;
        stringstream ss;
        ss<<i;
        ss>>s;
        se.insert(s);
    }
    /*
    set<string>::iterator it;
    for(it=se.begin();it!=se.end();it++)
    {
        cout<<*it<<endl;
    }
    */
    string a,b;
    cin>>a;
    getline(cin,b);//多读了一个空格
    if(se.count(a)&&se.count(b))
    {
        int ia,ib,ans;
        stringstream sa,sb;
        sa<<a;
        sb<<b;
        sa>>ia;
        sb>>ib;
        ans=ia+ib;
        cout<<a<<" + "<<b<<" = "<<ans;
    }
    else if(se.count(a)&&!se.count(b))
    {
        cout<<a<<" + ? = ?";
    }
    else if(!se.count(a)&&se.count(b))
    {
        cout<<"? + "<<b<<" = ?";
    }
    else
    {
        cout<<"? + ? = ?";
    }
    return 0;
}
