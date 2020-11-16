#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double v,c;//v和c全部弄成double型
    int a[100005],h[100005];
    int closable[100005];
    int out=0;
    int j=0;
    double s=0.0;
    cin>>n>>v>>c;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        s+=a[i];
    for(int i=0;i<n;i++)
    {
        if(h[i]==0)
        {
            closable[j]=a[i];
            j++;
        }
    }
    sort(closable,closable+j);//closable当中的数据存放正确
    j--;//j的值也正确

    /*for(int i=0;i<=j;i++)
        cout<<closable[i]<<" ";
    cout<<"\n";
    cout<<j<<endl;*/

    while(v*(a[0]/s)<c)
    {
        s-=closable[j];
        j--;
        out++;
        //cout<<v<<" "<<s<<" "<<a[0]<<" "<<c<<endl;
    }
    cout<<out;
    return 0;
}
