<<<<<<< HEAD
//use vector!!!
#include <bits/stdc++.h>
using namespace std;

int n,k;
long long sum;
long long s_max=0;/*output*/
long long square_sum=0;
int num[105];
int ans[15];/*output*/
int k_count=0;/*output*/

void dfs(int i,int ge,int he)
{
    if(i>=n||i<0)
        return;
    if(ge==k)
        return;
    ans[k_count]=num[i];
    k_count++;
    for(int j=i+1;j<n;j++)
    {
        dfs(j,ge+1,he+num[i]+num[j]);
    }
}

int main()
{
    cin>>n>>k>>sum;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n);/*sort*/
    for(int i=0;i<n;i++)
    {
        square_sum=0;
        k_count=0;
        dfs(i,1,0);
        if(square_sum>s_max)
            s_max=square_sum;
    }
    cout<<s_max<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<ans[i];
        if(i!=(k-1))
            cout<<" ";
    }
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

int main()
{

>>>>>>> 9af90ceeac5c04fe62e0fe9e1568cf5011516748
}
