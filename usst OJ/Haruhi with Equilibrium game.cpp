#include <bits/stdc++.h>
using namespace std;

int n,tp;
vector<int> v;
int con[500005];

void debug()
{
    for(int i=0;i<n;++i)
        cout<<con[i]<<" ";
    cout<<endl;
}

int main()
{
    v.clear();
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tp;
        v.push_back(tp);
    }
    bool allone=true;
    for(int i=0;i<n;++i){
        if(v[i]!=1){
            allone=false;
            break;
        }
    }
    if(allone){
        if(n&1){
            for(int i=0;i<n;++i)
                cout<<"Haruhi go first."<<endl;
        }
        else{
            for(int i=0;i<n;++i)
                cout<<"Haruhi go secondary."<<endl;
        }
    }
    else{
        for(int i=0;i<n;++i)
            v.push_back(v[i]);
        int ct=0;
        for(int i=v.size()-1;i>=0;--i){
            if(v[i]==1) ct++;
            else ct=0;
            if(ct>n)
                ct=n;
            con[i]=ct;
        }
        //debug();
        for(int i=0;i<n;++i){
            if(v[i]!=1){
                cout<<"Haruhi go first."<<endl;
                continue;
            }
            if(con[i]&1)
                cout<<"Haruhi go secondary."<<endl;
            else
                cout<<"Haruhi go first."<<endl;
        }
    }
    return 0;
}
