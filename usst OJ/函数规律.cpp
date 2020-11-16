#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string num;
    cin>>num;
    int sum=0;
    for(int i=0;i<10;i++)
    {
        if(num[i]=='0'||num[i]=='6'||num[i]=='9')
            sum++;
        else if(num[i]=='8')
            sum+=2;
        else;
    }
    cout<<sum<<endl;
    return 0;
}
