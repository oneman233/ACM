#include <bits/stdc++.h>
using namespace std;

int n,ans=-100;
string s[25];
char c;
int book[25];

int chk(string a,string b)
{
    int i=0,j=0;
    while(i<a.length()&&j<b.length()){
        if(a[i]!=b[j])
            break;
        i++;j++;
    }
    if(i==a.length()^j==b.length())
        return 0;
    for(i=a.length()-1;i>=0;--i){
        if(a[i]==b[0]){
            for(j=i;j<a.length();++j){
                if(a[j]!=b[j-i])
                    break;
            }
            if(j==a.length())
                return i;
        }
    }
    return 0;
}

string mer(string a,string b,int tmp)
{
    string out="";
    for(int i=0;i<tmp;++i)
        out.append(1,a[i]);
    for(int i=0;i<b.length();++i)
        out.append(1,b[i]);
    return out;
}

void dfs(int x,string tmp)
{
    ans=max(ans,(int)tmp.length());
    //cout<<tmp<<endl;
    for(int i=1;i<=n;++i){
        if(book[i]<2){
            int len=chk(tmp,s[i]);
            if(len!=0){
                book[i]++;
                //cout<<mer(tmp,s[i],len)<<endl;
                dfs(i,mer(tmp,s[i],len));
                book[i]--;
            }
        }
    }
}

int main()
{
    //cout<<chk("att","atide")<<endl;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    cin>>c;
    for(int i=1;i<=n;++i){
        if(s[i][0]==c){
            memset(book,0,sizeof(book));
            book[i]=1;
            dfs(i,s[i]);
        }
    }
    cout<<ans;
    return 0;
}
/*
2
abababab
abababc
a
*/
