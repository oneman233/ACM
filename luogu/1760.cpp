#include<bits/stdc++.h>
using namespace std;
    int a;
    stringstream b;
    string c;
int main()
{
    cin>>a;
    b.precision(0);//不输出小数位
    b<<fixed<<pow(2.0L,a);
    //fixed是用一般方式输出浮点数，而非科学记数法
    //2.0L代表是long double
    c=b.str();
    c[c.length()-1]--;//减一操作
    cout<<c;
}
