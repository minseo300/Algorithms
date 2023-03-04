#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
using namespace std;

int used[21];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력

    int m;
    cin>>m;
    string order;
    int num;

    for(int i=0;i<m;i++){
        cin>>order;
        
        // int split=order.find(" ");
        // order=order.substr(0,split);
        // num=stoi(order.substr(split,order.length()-split));
        // cout<<order<<" "<<num<<"\n";
        if(order=="add"){
            cin>>num;
            used[num]=1;
        }
        else if(order=="remove"){
            cin>>num;
            used[num]=0;
        }
        else if(order=="check"){
            cin>>num;
            if(used[num]==1) cout<<"1\n";
            else cout<<"0\n";
        }
        else if(order=="toggle"){
            cin>>num;
            if(used[num]==1) used[num]=0;
            else used[num]=1;
        }
        else if(order=="all"){
            for(int i=1;i<=20;i++){
                used[i]=1;
            }
        }
        else if(order=="empty"){
            for(int i=0;i<=20;i++){
                used[i]=0;
            }
        }
        // for(int i=1;i<21;i++){
        //     cout<<i<<" "<<used[i]<<"\n";
        // }
    }


    
    
    return 0;
}