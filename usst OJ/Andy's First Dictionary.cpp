#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> s;
    string a,b;
    while(cin>>a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(isalpha(a[i]))
                a[i]=tolower(a[i]);//������д
            else
                a[i]=' ';//�ո���string�����лᱻ����
        }
        stringstream temp(a);
        while(temp>>b)//��ֹ����
            s.insert(b);
    }
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<"\n";
    return 0;
}
