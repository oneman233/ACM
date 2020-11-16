#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    auto file = fopen("in.txt","w");
    fprintf(file,"90000 2 12\n");
    srand(time(0));
    int flag=1;
    for(int i=1;i<=90000;++i){
        int tmp=rand()%1000000000;
        tmp+=82653471;
        tmp%=18;
        if(flag)
            tmp-=29,
            flag=0;
        else
            flag=1;
        fprintf(file,"%d ",tmp);
    }
    fclose(file);
    return 0;
}
