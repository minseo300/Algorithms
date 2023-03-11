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
int map[17][17];
int dp[17][17][3];

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
        }
    }

    dp[0][1][0]=1;
    for(int i=2;i<n;i++){
        if(map[0][i]==1) continue;
        dp[0][i][0]=dp[0][i-1][0];
    }

    for(int i=1;i<n;i++){
        for(int j=2;j<n;j++){
            if(map[i][j]==1) continue;

            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][2];
            dp[i][j][1]=dp[i-1][j][1]+dp[i-1][j][2];
            if(map[i-1][j]==1||map[i][j-1]==1) continue;
            dp[i][j][2]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
        }
    }
    cout<<dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2]<<"\n";
    return 0;
}
