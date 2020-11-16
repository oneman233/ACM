#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n[11];
    for(int i=0;i<11;i++)
        n[i]=str[i]-'0';
    set<int> s;
    set<int>::iterator it;
    for(int i=0;i<11;i++)
        s.insert(n[i]);
    vector<int> arr;
    for(it=s.begin();it!=s.end();it++)
        arr.push_back(*it);
    vector<int> temp;
    for(int i=arr.size()-1;i>=0;i--)
        temp.push_back(arr[i]);
    arr.clear();
    for(int i=0;i<temp.size();i++)
        arr.push_back(temp[i]);
    vector<int> index;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(n[i]==arr[j])
            {
                index.push_back(j);
                break;
            }
        }
    }
    cout<<"int[] arr = new int[]{";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i];
        if(i!=arr.size()-1)
            cout<<",";
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i=0;i<11;i++)
    {
        cout<<index[i];
        if(i!=10)
            cout<<",";
    }
    cout<<"};";
    return 0;
}
