#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

int n;
char alpha;
string s;

void work()
{
    n=s.length();
    int flg=1;
    vector<double> lidx,ridx,lnum,rnum;
    for(int i=0;i<n;++i){
        if(s[i]=='=')
            flg=0;
        if(isdigit(s[i])){
            int ch=1,j;
            for(j=i;j<n;++j)
                if(!isdigit(s[j]))
                    break;
            if(i-1>=0){
                if(s[i-1]=='-')
                    ch=-1;
                else
                    ch=1;
            }
            stringstream ss;
            double tmp;
            if(isalpha(s[j])){
                alpha=s[j];
                ss<<s.substr(i,j-i);
                ss>>tmp;
                tmp*=ch;
                if(flg)
                    lidx.pb(tmp);
                else
                    ridx.pb(tmp);
            }
            else{
                //cout<<s.substr(i,j-i)<<endl;
                ss<<s.substr(i,j-i);
                ss>>tmp;
                tmp*=ch;
                if(flg)
                    lnum.pb(tmp);
                else
                    rnum.pb(tmp);
            }
            i=j-1;
        }
        else if(isalpha(s[i])){
            alpha=s[i];
            if(i-1>=0){
                if(isdigit(s[i-1]))
                    continue;
                if(s[i-1]=='-'){
                    if(flg)
                        lidx.pb(-1.0);
                    else
                        ridx.pb(-1.0);
                }
                else{
                    if(flg)
                        lidx.pb(1.0);
                    else
                        ridx.pb(1.0);
                }
            }
            else{
                if(flg)
                    lidx.pb(1.0);
                else
                    ridx.pb(1.0);
            }
        }
    }
    double lidxsum=0.0,ridxsum=0.0,lnumsum=0.0,rnumsum=0.0;
    for(int i=0;i<lidx.size();++i)
        lidxsum+=lidx[i];
    for(int i=0;i<ridx.size();++i)
        ridxsum+=ridx[i];
    for(int i=0;i<lnum.size();++i)
        lnumsum+=lnum[i];
    for(int i=0;i<rnum.size();++i)
        rnumsum+=rnum[i];
    //cout<<lidxsum<<' '<<ridxsum<<endl;
    //cout<<lnumsum<<' '<<rnumsum<<endl;
    lidxsum-=ridxsum;
    rnumsum-=lnumsum;
    printf("%c=%.3lf",alpha,rnumsum/lidxsum+1e-6);
}

int main()
{
    cin>>s;
    work();
    return 0;
}
/*
-a+1a-3=a-3
*/
