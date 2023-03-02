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

int m,n; // 세로, 가로
int map[500][500];
int used[500][500];
int dp[500][500];
int ans=0;
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int dfs(int y,int x){
    if(y==n-1&&x==m-1){
        return 1;
    }
    if(used[y][x]==1) return dp[y][x];
    used[y][x]=1;
    for(int d=0;d<4;d++){
        int dy=y+direct[d][0];
        int dx=x+direct[d][1];

        if(dy<0||dx<0||dy>=n||dx>=m) continue;
        if(map[y][x]<=map[dy][dx]) continue;
        dp[y][x]+=dfs(dy,dx);
    }
    return dp[y][x];
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>map[y][x];
        }
    }
    cout<<dfs(0,0)<<"\n";
    

    return 0;
}