#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<b;++i)
#define _rep(i,a,b) for(int i=a;i<=b;++i)
#define sci(a) scanf("%d",&a)
#define scc(a) scanf("%c",&a)
#define pri(a) printf("%d",a)
#define prc(a) printf("%c",a)
#define prn() printf("\n")
using namespace std;
typedef long long ll;
const ll Max=1000000;

string inord,postord;

void build(int inleft,int inright,int postleft,int postright)
{
    if(inleft<0||inright>=inord.length()||postleft<0||postright>=postord.length())
        return;
    if(inleft>inright||postleft>postright)
        return;
    ///printf("%d %d %d %d\n",inleft,inright,postleft,postright);
    char root=postord[postright];
    prc(root);
    int pos;
    for(pos=inleft;pos<=inright;++pos)
        if(inord[pos]==root)
            break;
    int cnt=pos-inleft;///这才是左子树节点数
    build(inleft,pos-1,postleft,postleft+cnt-1);
    build(pos+1,inright,postleft+cnt,postright-1);
}

int main()
{
    cin>>inord>>postord;
    build(0,inord.length()-1,0,postord.length()-1);
    return 0;
}
