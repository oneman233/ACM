#include <bits/stdc++.h>
using namespace std;

int n,q,tmp,id;
map<int,int> m;
char c;

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&tmp);
        m[tmp]=i;
    }
    int l=1,r=n;
    while(q--){
        getchar();
        scanf("%c %d",&c,&id);
        if(c=='L'){
            l--;
            m[id]=l;
        }
        else if(c=='R'){
            r++;
            m[id]=r;
        }
        else if(c=='?'){
            int pos=min(r-m[id],m[id]-l);
            printf("%d\n",pos);
        }
    }
    return 0;
}
