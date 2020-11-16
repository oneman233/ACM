#include <bits/stdc++.h>
using namespace std;

string a,b;

bool judge()
{
    if((a[0]!='-'&&b[0]!='-')||(a[0]=='-'&&b[0]=='-'))
        return false;
    else if(a[0]=='-'&&b[0]!='-'){
        if(a.length()!=b.length()+1)
            return false;
        else{
            for(int i=1;i<a.length();++i)
                if(a[i]!=b[i-1])
                    return false;
            return true;
        }
    }
    else if(a[0]!='-'&&b[0]=='-'){
        if(b.length()!=a.length()+1)
            return false;
        else{
            for(int i=1;i<b.length();++i)
                if(b[i]!=a[i-1])
                    return false;
            return true;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a=="0"&&b=="0"){
            cout<<"true"<<endl;
            continue;
        }
        if(judge())
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
