#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num[9]={1,2,3,4,5,6,7,8,9};
    int n,i=0;
    cin>>n;
    do
    {
        for(i=0;i<n;i++)
            cout<<num[i];
        cout<<endl;
    }while(next_permutation(num,num+n));
    return 0;
}
