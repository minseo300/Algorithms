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
int m;
int cups[4];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>m;
    cups[1]=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        swap(cups[x],cups[y]);
        
    }
    for(int i=1;i<=3;i++){
        if(cups[i]==1){
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}
