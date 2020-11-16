#include <bits\stdc++.h>
using namespace std;

int t=0,s=0;

void chk(int a,int b,int c){
    if(a+b>c&&a+c>b&&b+c>a){
        //cout<<a<<' '<<b<<' '<<c<<endl;
        t++;
        return;
    }
    if(a+b>=c&&a+c>=b&&b+c>=a){
        s++;
        return;
    }
}

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    chk(a,b,c);
    chk(a,c,d);
    chk(b,c,d);
    chk(a,b,d);
    if(t!=0)
        cout<<"TRIANGLE";
    else if(t==0&&s!=0)
        cout<<"SEGMENT";
    else
        cout<<"IMPOSSIBLE";
    return 0;
}
