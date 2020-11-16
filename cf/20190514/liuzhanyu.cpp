#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pr;
const ll mxn = 2e5+5;
const ll mxm = 10;
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9+7;

int n,x,y;
char s[mxn];
int main(void)
{
    cin>>n;
    s[n+1]='0';
    s[0]='0';
    s[n+2]='\0';
    char temp;
    int pos=0,cnt=0;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(i==1) {
            s[++pos]=temp;
            continue;
        }
        if((pos%2==1)&&temp==s[pos]){
            cnt++;
        }
        else{
            s[++pos]=temp;
        }
    }
    if(pos%2==1){pos--;cnt++;}
    printf("%d\n",cnt);
    for(int i=1;i<=pos;i++){
        printf("%c",s[i]);
    }
//    printf("%s",s);

}
