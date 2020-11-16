#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[9]={1,2,3,4,5,6,7,8,9};
    do
    {
        int a=num[0]*100+num[1]*10+num[2];
        int b=num[3]*100+num[4]*10+num[5];
        int c=num[6]*100+num[7]*10+num[8];
        if(2*a==b&&3*a==c)
            cout<<a<<" "<<b<<" "<<c<<endl;
    }
    while(next_permutation(num,num+9));
    return 0;
}
