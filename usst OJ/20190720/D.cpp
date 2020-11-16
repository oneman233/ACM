#include <bits/stdc++.h>
using namespace std;

string s;
int ans,len;

int main()
{
    cin>>s;
    len=s.length();
    ans=len;
    for(int i=0;i<len;++i){
        for(int j=i;j<len;++j){
            string tmp=s.substr(i,j-i+1);
            int cnt=0,ll=j-i+1;
            for(int k=0;k+ll-1<len;++k){
                if(s.substr(k,ll)==tmp){
                    cnt++;
                    k=k+ll-1;
                }
            }
            //cout<<tmp<<' '<<cnt<<endl;
            ans=min(ans,cnt+len-cnt*ll+ll);
        }
    }
    printf("%d",ans);
    return 0;
}
///NWEWWSWEWWEWWNEWSWEWW
