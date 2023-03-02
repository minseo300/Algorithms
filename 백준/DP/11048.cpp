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

int map[1001][1001];
int dp[1001][1001];
int n,m;
int used[1000][1000];
int direct[3][2]={
    1,0,
    0,1,
    1,1
};

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    dp[1][1]=map[1][1];
    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            for(int d=0;d<3;d++){
                int dy=y+direct[d][0];
                int dx=x+direct[d][1];

                if(dy<0||dx<0||dy>n||dx>m) continue;

                if(map[dy][dx]+dp[y][x]>dp[dy][dx]) dp[dy][dx]=map[dy][dx]+dp[y][x];
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}