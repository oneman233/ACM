#include <bits/stdc++.h>
using namespace std;

string mul(string a,string b)
{
    vector<int> v;
    for(int i=a.length()-1;i>=0;--i){
        int cnt=0;
        for(int j=b.length()-1;j>=0;--j)
            cnt+=(a[i]-'0')*(b[j]-0);
        v.push_back(cnt);
    }
    for(int i=v.size()-1;i>=1;--i){
        if(v[i]>=10){
            v[i-1]+=v[i]/10;
            v[i]%=10;
        }
    }
    while(v[0]>=10){
        v.insert(v[0]/10,v.begin());
        v[1]%=10;
    }
    string ans="";
    for(int i=0;i<v.size();++i)
        ans.append(1,v[i]+'0');
    return ans;
}

bool isbig(string a,string b)
{
    if(a.length()>b.length())
        return true;
    else if(a.length()<b.length())
        return false;
    else{
        for(int i=0;i<a.length();++i){
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        }
        return false;
    }
}

int main()
{
    int n,k;
    char a[45];
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    if(k==1){

    }
    else if(k==2){

    }
    else if(k==3){

    }
    else if(k==4){

    }
    else if(k==5){

    }
    else if(k==6){

    }
    return 0;
}
