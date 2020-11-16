#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define elif else if

string dic[10];
char tmps[100005];

int main()
{
    int _t;
    int _n;
    string s = "";
    scanf("%d",&_t);
    while(_t--){
        scanf("%d",&_n);
        while(_n--){
            string ans="";
            for(int i=0;i<10;i++){
                scanf(" %[^\n]",tmps);
                s=string(tmps);
                if(i==0 || i==9)continue;
                //if(i==8)s[s.length()-1]='\0';
                //else s[s.length()-2]='\0';
                if(s[0]=='t')dic[1]=s.substr(7,s.length()-8);
                elif(s[0]=='a')dic[0]=s.substr(8,s.length()-9);
                elif(s[0]=='j')dic[2]=s.substr(9,s.length()-10);
                elif(s[0]=='v')dic[4]=s.substr(8,s.length()-9);
                elif(s[0]=='n')dic[5]=s.substr(8,s.length()-9);
                elif(s[0]=='p'){
                    if(s[1]=='a')dic[6]=s.substr(7,s.length()-8);
                    else continue;
                }
                else dic[3]=s.substr(6,s.length()-7);
            }
            int flag=0;
            for(int i=0;i<dic[0].length();i++)
            {
                if(flag)
                {
                    ans+=", ";
                }
                ans+=dic[0][i];
                ans+=dic[0][i+1];
                ans+=". ";
                flag=1;
                while(dic[0][i]!=' '&&i<dic[0].length())
                {
                    i++;
                }
                if(i+1>=dic[0].length()) break;
                ans+=dic[0][i+1];
                while(dic[0][i]!=','&&i<dic[0].length())
                {
                    i++;
                }
                i+=1;
            }
            /*int cur=0;
            while(cur<dic[0].length())
            {
            	if(flag) ans+=", ";
            	flag++;
				ans+=dic[0][cur],ans+=dic[0][cur+1];
            	ans+=". ";
            	while(cur<dic[0].length()
            }*/
            ans += ". ";
            for(auto c:dic[1]) if(c!='}') ans+=c; else break;
            //ans = ans + dic[1];
            ans += ". ";
            
            for(auto c:dic[2]) if(c!='}') ans+=c; else break;
            //ans += dic[2];
            ans += ". ";
            
            for(auto c:dic[3]) if(c!='}') ans+=c; else break;
            //ans += dic[3];
            ans += ";";
            
            for(auto c:dic[4]) if(c!='}') ans+=c; else break;
            //ans += dic[4];
            ans += "(";
            
            for(auto c:dic[5]) if(c!='}') ans+=c; else break;
            //ans += dic[5];
            ans += "):";
            
            for(auto c:dic[6]) if(c!='}') ans+=c; else break;
            //ans += dic[6];
            ans += ".";
            printf("%s\n",ans.c_str());
        }
    }
    return 0;
}

/*
1
1
@article{
pages={139347211214394105437304731788634704371711637363295575651423593677679-075745},
title={huToGAD YlnpQ gCukKXcbRW iziaHzkIaVOFDk},
journal={UICPncLTBgAv LXoDPeZAANJq oA NNEObctwJbzNbCbAGIZAmSKfZNy AR},
volume={5549110802578239227018294612716038479276439851666376042498672171703151551899439321338458430},
number={08949237236127731577351670127006483},
year={4052994446594380764668},
publisher={D Jf VhjgKxswMUM VIm bsgM Po wj hf G z A PuVIcgvRomoH VpyCHwoDR erMJw RyIL i},
author={Sb B},
}
*/
