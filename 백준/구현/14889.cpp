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

int n;
int map[21][21];
int start[21];
vector<int> link;
int used[21];
int ans=21e8;
int cal_start(){
    int sum=0;
    for(int i=0;i<n/2;i++){
        for(int j=i+1;j<n/2;j++){
            // cout<<start[i]<<" "<<start[j]<<"\n";
            sum+=map[start[i]][start[j]]+map[start[j]][start[i]];
            // cout<<"sum: "<<sum<<"\n";
        }
    }
    return sum;
}
int cal_link(){
     int sum=0;
    for(int i=0;i<n/2;i++){
        for(int j=i+1;j<n/2;j++){
            // cout<<link[i]<<" "<<link[j]<<"\n";
            sum+=map[link[i]][link[j]]+map[link[j]][link[i]];
        }
        
    }
    return sum;
}
void dfs(int p,int lev){
    if(lev==n/2){
        int start_score=cal_start();
        for(int i=1;i<=n;i++){
            if(used[i]==0) link.push_back(i);
        }
        int link_score=cal_link();
        // cout<<"- "<<start_score<<" "<<link_score<<" "<<abs(start_score-link_score)<<"\n";
        // for(int i=0;i<n/2;i++){
        //     cout<<start[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n/2;i++){
        //     cout<<link[i]<<" ";
        // }
        // cout<<"\n";
        ans=min(ans,abs(start_score-link_score));
        link.clear();
        // cout<<"\n";
        return;
    }

    for(int i=p+1;i<=n;i++){
        start[lev]=i;
        used[i]=1;
        dfs(i,lev+1);
        used[i]=0;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin>>map[y][x];
        }
    }
    start[0]=1;
    used[1]=1;
    dfs(1,1);
    cout<<ans<<"\n";
    
    return 0;
}
