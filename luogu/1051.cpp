#include <bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    int pingjun,pingyi;
    char isganbu,isxibu;
    int lunwen;
    int v=0;
    void cal()
    {
        if(pingjun>80&&lunwen>=1)
            v+=8000;
        if(pingjun>85&&pingyi>80)
            v+=4000;
        if(pingjun>90)
            v+=2000;
        if(pingjun>85&&isxibu=='Y')
            v+=1000;
        if(pingyi>80&&isganbu=='Y')
            v+=850;
    }
}stu[110];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>stu[i].name>>stu[i].pingjun>>stu[i].pingyi>>stu[i].isganbu>>stu[i].isxibu>>stu[i].lunwen;
        stu[i].cal();
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(stu[j].v>stu[i].v)
                swap(stu[i],stu[j]);
        }
    }
    cout<<stu[0].name<<endl;
    cout<<stu[0].v<<endl;
    int sum=0;
    for(int i=0;i<n;++i)
        sum+=stu[i].v;
    cout<<sum;
    return 0;
}
