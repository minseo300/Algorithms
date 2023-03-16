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

struct Node{
    int y,x;
};
Node map[26];
int n;
vector<vector<Node>> row(5);
vector<vector<Node>> col(5);
vector<vector<Node>> cross(2);
int check(){
    int cnt=0;
    for(int i=0;i<5;i++){
        if(row[i].size()==5) cnt++;
        if(col[i].size()==5) cnt++; 
    }
    for(int i=0;i<2;i++){
        if(cross[i].size()==5) cnt++;
    }

    if(cnt>=3) return 1;
    return 0;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            cin>>n;
            map[n]={y,x};
        }
    }
    // for(int i=1;i<=25;i++) cout<<map[i].y<<" "<<map[i].x<<"\n";
    int flag=0;
    int ans=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>n;
            int y=map[n].y;
            int x=map[n].x;
            // cout<<y<<" "<<x<<"\n";
            // cout<<"-"<<n<<"\n";
            row[y].push_back({y,x});
            col[x].push_back({y,x});
            if(y==x) cross[0].push_back({y,x});
            if(y+x==4) cross[1].push_back({y,x});

            // for(int k=0;k<5;k++){
            //     printf("row[%d] size: %d\n",k,row[k].size());
            //     printf("col[%d] size: %d\n",k,col[k].size());
            // }
            // for(int k=0;k<2;k++){
            //     printf("cross[%d] size: %d\n",k,cross[k].size());

            // }
            if(check()) {
                cout<<ans<<"\n";
                flag=1;
                break;
            }
            else{
                ans++;
            }
        }
        if(flag==1) break;
    }
    cout<<"\n";
    return 0;
}
