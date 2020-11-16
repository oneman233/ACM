#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define sci(a) scanf("%d",&a)
#define scc(a) scanf("%c",&a)
#define prc(a) printf("%c",a)
#define prn() printf("\n")
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;
const ll Max=1000000;

map<char,char> l,r;

void build(char baba)
{
    if(baba=='*')
        return;
    prc(baba);
    build(l[baba]);
    build(r[baba]);
}

int main()
{
    int n;
    /*
    vector<char> root;
    map<char,bool> isroot;
    */
    char god;
    cin>>n;
    _for(i,0,n)
    {
        char father,leftchild,rightchild;
        cin>>father>>leftchild>>rightchild;
        if(i==0)
            god=father;
        l[father]=leftchild;///连接到左树
        r[father]=rightchild;///连接到右树
        /*
        root.pb(father);///储存节点
        isroot[father]=true;
        */
    }
    /*
    _for(i,0,root.size())
    {
        isroot[l[root[i]]]=false;
        isroot[r[root[i]]]=false;
    }
    _for(i,0,root.size())
    {
        if(isroot[root[i]])
        {
            god=root[i];
            break;
        }
    }
    */
    build(god);
    return 0;
}
