#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,a[100005];
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int temp=0;
    for(int i=0;i<n;++i){
        temp+=a[i];
        a[i]=temp;
    }
    for(int i=0;i<n;++i)
        a[i]%=k;
    /*
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    */
    ///ʵ����Ҫ���ǵ��ǰ���Щ������ͬ�ĸ㵽һ����ſ��Թ������K�����䡱
    map<int,int> m;
    int ans=0;
    for(int i=0;i<n;++i){
        if(a[i]==0)
            ++ans;
        ans+=m[a[i]];
        m[a[i]]++;
    }
    cout<<ans;
    return 0;
}
