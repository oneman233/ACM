#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[4];
    int i;
    for(i=0;i<4;i++)
        cin>>num[i];
    if(num[3]>num[2]&&num[2]>num[1]&&num[1]>num[0])
        cout<<"Fish Rising";
    else if(num[3]<num[2]&&num[2]<num[1]&&num[1]<num[0])
        cout<<"Fish Diving";
    else if(num[3]==num[2]&&num[2]==num[1]&&num[1]==num[0])
        cout<<"Fish At Constant Depth";
    else
        cout<<"No Fish";
    return 0;
}
