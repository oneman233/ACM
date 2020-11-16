#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;

bool isrxcy()
{
    for(int i=0;i<s.length()-1;++i){
        if(s[i]=='C'&&isdigit(s[i-1])&&isdigit(s[i+1]))
            return true;
    }
    return false;
}

string to26(int x)
{
    string tp="";
    while(x){
        int rm=x%26;
        if(rm==0){
            rm=26;
            x-=26;
        }
        tp.append(1,rm-1+'A');
        x/=26;
    }
    reverse(tp.begin(),tp.end());
    return tp;
}

int pow(int x)
{
    int as=1;
    for(int i=1;i<=x;++i)
        as*=26;
    return as;
}

int cal26(string tp)
{
    int bs=pow(tp.length()-1),as=0;
    for(int i=0;i<tp.length();++i){
        as+=(tp[i]-'A'+1)*bs;
        bs/=26;
    }
    return as;
}

void chg()
{
    if(isrxcy()){
        for(int i=0;i<s.length();++i){
            if(isalpha(s[i]))
                s[i]=' ';
        }
        stringstream ss;
        ss<<s;
        string x;
        int y;
        ss>>x;
        ss>>y;
        cout<<to26(y)<<x<<endl;
    }
    else{
        int ix=0;
        while(isalpha(s[ix]))
            ix++;
        cout<<"R"<<s.substr(ix,s.length()-ix)<<"C"<<cal26(s.substr(0,ix))<<endl;
    }
}

void debug()
{
    for(int i=1;i<=1000;++i){
        cout<<to26(i)<<endl;
    }
}

signed main()
{
    ///debug();
    cin>>n;
    while(n--){
        cin>>s;
        chg();
    }
    return 0;
}
/*
100
R1C520
R1C521
R1C26
R1C27
R1C519
R1C25
*/
