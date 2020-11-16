#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

struct node{
    int x;
    int y;
    bool operator < (struct node a) const{
        if(this->x == a.x){
            return this->y < a.y;
        }
        return this->x < a.x;
    }
};

map<int,struct node> ma;
map<int ,int> ma2;

int result[6];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int a[6] ={4,8,15,16,23,42};
    for(int i = 0; i< 6 ;i++){
        for(int j = 0; j< 6 ;j++){
            if(i == j){
                continue;
            }
            struct node temp;
            temp.x = a[i];
            temp.y = a[j];
            ma[a[i]*a[j]] = temp;
        }
    }
    set<int> se;
    for(int i = 0; i<2;i++){
        fflush(stdout);
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        int res;
        cin>>res;
        struct node temp = ma[res];
        ma2[temp.x]++;
        ma2[temp.y]++;
        int j = 0;
        if(i == 0){
            se.insert(temp.x);
            se.insert(temp.y);
        }

        for(auto it = ma2.begin();it !=ma2.end();it++){
            if(it->second == 2){
                result[i] = it->first;
                it->second = 0;
                if(!se.empty()){
                    se.erase(se.find(it->first));
                }
                break;
            }
            j++;
        }
        if(i == 1){
            result[0] = *se.begin();
            se.clear();
            ma2[result[0]] = 0;
            for(auto it = ma2.begin();it!=ma2.end();it++){
                if(it->second == 1){
                    result[2] = it->first;
                }
            }
        }
    }
    ma2.clear();
    se.clear();
    for(int i = 3; i<5;i++){
        fflush(stdout);
        cout<<"? "<<i+1<<" "<<i+2<<endl;
        int res;
        cin>>res;
        struct node temp = ma[res];
        ma2[temp.x]++;
        ma2[temp.y]++;
        int j = 0;
        if(i == 3){
            se.insert(temp.x);
            se.insert(temp.y);
        }
        for(auto it = ma2.begin();it !=ma2.end();it++){
            if(it->second == 2){
                result[i] = it->first;
                it->second = 0;
                if(!se.empty()){
                    se.erase(se.find(it->first));
                }
                break;
            }
            j++;
        }
        if(i == 4){
            result[3] = *se.begin();
            se.clear();
            ma2[result[3]] = 0;
            for(auto it = ma2.begin();it!=ma2.end();it++){
                if(it->second == 1){
                    result[5] = it->first;
                }
            }
        }
    }
    cout<<"! ";
        for(int i = 0; i<6;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    return 0;
}
