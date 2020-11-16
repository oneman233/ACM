#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;

int t,n;
int trie[maxn][10],tot=1;
bool isend[maxn],can=false;
string s;

void add(string s)
{
    int flag=1;
    for(int i=0;i<s.length();++i){
        int pos=s[i]-'0';
        if(trie[flag][pos]==0)
            trie[flag][pos]=++tot;
        flag=trie[flag][pos];
    }
    isend[flag]=true;
}

bool ask(string s)
{

}

void init()
{
   memset(trie,0,sizeof(trie));
   tot=1;
   memset(isend,0,sizeof(isend));
   can=false;
}

int main()
{
    cin>>t;
    while(t--){
        init();
        cin>>n;
        while(n--){
            cin>>s;
            add(s);
        }
        for(int i=1;i<=tot;++i){
            if(isend[i]){
                for(int j=0;j<=9;++j){
                    if(trie[i][j]!=0){
                        can=true;
                        break;
                    }
                }
                if(can)
                    break;
            }
        }
        if(can)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
