#include <bits/stdc++.h>
using namespace std;

inline int qgcd(int a, int b)
{
    int i=0,j=0;
    for(;0 == (a&1);++i) a>>=1;
    for(;0 == (b&1);++j) b>>=1;
    i = i>j? j : i;
    ///只有较小的2的个数才可以对结果产生影响
    while(1){
        if(a < b)
            swap(a,b);
            ///保证a>b
            a-=b;
            ///辗转相减
        if(0 == a)
            return b<<i;
        while(0 == (a&1))
            a>>=1;
    }
}

int main()
{
    cout<<qgcd(15, 20)<<endl;
    cout<<qgcd(8, 5)<<endl;
    cout<<qgcd(9, 6)<<endl;
    cout<<qgcd(34, 51)<<endl;
    return 0;
}
