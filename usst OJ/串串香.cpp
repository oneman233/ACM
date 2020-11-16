#include <bits/stdc++.h>
using namespace std;
const int MAX=100000;

string w1,w2;
int p1[MAX+5],p2[MAX+5];

void getp1()
{
    int j=0;
    p1[0]=p1[1]=0;
    for(int i=1;i<w1.length();++i){
        while(j&&w1[j]!=w1[i])
            j=p1[j];
        if(w1[j]==w1[i])
            j++;
        p1[i+1]=j;
    }
}

void getp2()
{
    int j=0;
    p2[0]=p2[1]=0;
    for(int i=1;i<w2.length();++i){
        while(j&&w2[j]!=w2[i])
            j=p1[j];
        if(w2[j]==w2[i])
            j++;
        p2[i+1]=j;
    }
}

string re(string a)
{
    string b="";
    for(int i=a.length()-1;i>=0;--i)
        b.append(1,a[i]);
    return b;
}

bool kmp1(string a)
{
    int j=0;
    for(int i=0;i<a.length();++i){
        while(j&&w1[j]!=a[i]&&a[i]!='?')
            j=p1[j];
        if(w1[j]==a[i]||a[i]=='?')
            j++;
        if(j==w1.length())
            return true;
    }
    return false;
}

bool kmp2(string a)
{
    int j=0;
    for(int i=0;i<a.length();++i){
        while(j&&w2[j]!=a[i]&&a[i]!='?')
            j=p2[j];
        if(w2[j]==a[i]||a[i]=='?')
            j++;
        if(j==w2.length())
            return true;
    }
    return false;
}

int main()
{
    cin>>w1;
    getp1();
    w2=re(w1);
    getp2();
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(kmp1(s)||kmp2(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
