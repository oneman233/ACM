#include <bits/stdc++.h>

using namespace std;

bool light[10];

void output()
{
    for(int i=1;i<=9;i++)
    {
        if(light[i]==false)
            cout<<"0";
        else
            cout<<"1";
    }
    cout<<"\n";
}

bool check()
{
    int ans=0;
    for(int i=1;i<=9;i++)
    {
        if(light[i]==true)
        {
            ans++;
        }
    }
    if(ans==4)
        return true;
    else
        return false;
}


void kaiguan(int i)
{
    if(i==1)
    {
        if(light[2]==true)
            light[2]=false;
        else
            light[2]=true;
        if(light[4]==true)
            light[4]=false;
        else
            light[4]=true;
    }
    else if(i==2)
    {
        if(light[1]==true)
            light[1]=false;
        else
            light[1]=true;
        if(light[3]==true)
            light[3]=false;
        else
            light[3]=true;
        if(light[5]==true)
            light[5]=false;
        else
            light[5]=true;
    }
    else if(i==3)
    {
        if(light[2]==true)
            light[2]=false;
        else
            light[2]=true;
        if(light[6]==true)
            light[6]=false;
        else
            light[6]=true;
    }
    else if(i==4)
    {
        if(light[1]==true)
            light[1]=false;
        else
            light[1]=true;
        if(light[5]==true)
            light[5]=false;
        else
            light[5]=true;
        if(light[7]==true)
            light[7]=false;
        else
            light[7]=true;
    }
    else if(i==5)
    {
        if(light[2]==true)
            light[2]=false;
        else
            light[2]=true;
        if(light[4]==true)
            light[4]=false;
        else
            light[4]=true;
        if(light[6]==true)
            light[6]=false;
        else
            light[6]=true;
        if(light[8]==true)
            light[8]=false;
        else
            light[8]=true;
    }
    else if(i==6)
    {
        if(light[3]==true)
            light[3]=false;
        else
            light[3]=true;
        if(light[5]==true)
            light[5]=false;
        else
            light[5]=true;
        if(light[9]==true)
            light[9]=false;
        else
            light[9]=true;
    }
    else if(i==7)
    {
        if(light[4]==true)
            light[4]=false;
        else
            light[4]=true;
        if(light[8]==true)
            light[8]=false;
        else
            light[8]=true;
    }
    else if(i==8)
    {
        if(light[5]==true)
            light[5]=false;
        else
            light[5]=true;
        if(light[7]==true)
            light[7]=false;
        else
            light[7]=true;
        if(light[9]==true)
            light[9]=false;
        else
            light[9]=true;
    }
    else if(i==9)
    {
        if(light[6]==true)
            light[6]=false;
        else
            light[6]=true;
        if(light[8]==true)
            light[8]=false;
        else
            light[8]=true;
    }
    else;
}

int main()
{
    for(int i=0;i<=9;i++)
        light[i]=false;
    for(int i=0;i<(1<<9);i++)
    {
        for(int i=0;i<=9;i++)
            light[i]=false;
        for(int j=8;j>=0;j--)
        {
            if(i&(1<<j))
            {
                kaiguan(9-j);
            }
        }
        if(check())
        {
            for(int j=8;j>=0;j--)
            {
                if(i&(1<<j))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
