#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ans=100000;

void check(int i)
{
    int sum=0;
    if(s[i]=='A')
        sum+=0;
    else
        sum+=min(s[i]-'A','Z'+1-s[i]);
    if(s[i+1]=='C')
        sum+=0;
    else if(s[i+1]>'C')
        sum+=min(s[i+1]-'C','Z'+1+'C'-'A'-s[i+1]);
    else
        sum+=min('C'-s[i+1],s[i+1]-'A'+1+'Z'-'C');
    if(s[i+2]=='T')
        sum+=0;
    else if(s[i+2]>'T')
        sum+=min(s[i+2]-'T','Z'+1+'T'-'A'-s[i+2]);
    else
        sum+=min('T'-s[i+2],s[i+2]-'A'+1+'Z'-'T');
    if(s[i+3]=='G')
        sum+=0;
    else if(s[i+3]>'G')
        sum+=min(s[i+3]-'G','Z'+1+'G'-'A'-s[i+3]);
    else
        sum+=min('G'-s[i+3],s[i+3]-'A'+1+'Z'-'G');
    ans=min(ans,sum);
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<=n-4;i++)
        check(i);
    cout<<ans;
    return 0;
}
