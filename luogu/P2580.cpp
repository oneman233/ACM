#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;

int n;
string s;
int trie[maxn][26],tot=1,ise[maxn];

void add(string s)
{
    int p=1;
    for(int i=0;i<s.length();++i){
        if(trie[p][s[i]-'a']==0)
            trie[p][s[i]-'a']=++tot;
        p=trie[p][s[i]-'a'];
    }
    ise[p]++;
}

void ask(string s)
{
    int p=1;
    for(int i=0;i<s.length();++i){
        if(trie[p][s[i]-'a']==0){
            cout<<"WRONG"<<endl;
            return;
        }
        p=trie[p][s[i]-'a'];
    }
    if(ise[p]==0)
        cout<<"WRONG"<<endl;
    else if(ise[p]==1){
        cout<<"OK"<<endl;
        ise[p]++;
    }
    else
        cout<<"REPEAT"<<endl;
}

int main()
{
    cin>>n;
    while(n--){
        cin>>s;
        add(s);
    }
    cin>>n;
    while(n--){
        cin>>s;
        ask(s);
    }
    return 0;
}
