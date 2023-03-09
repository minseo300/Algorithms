#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
#include <map>
using namespace std;

int board[2][100001];
int dp[2][100001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int t,n;
    cin>>t;
    for(int tc=0;tc<t;tc++){
        cin>>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>board[i][j];
            }
        }
        dp[0][0]=board[0][0]; dp[1][0]=board[1][0];
        dp[0][1]=board[1][0]+board[0][1];  dp[1][1]=board[1][1]+board[0][0];
        for(int i=2;i<n;i++){
            dp[0][i]=max(dp[0][i-2],max(dp[1][i-2],dp[1][i-1]))+board[0][i];
            dp[1][i]=max(dp[0][i-2],max(dp[1][i-2],dp[0][i-1]))+board[1][i];
        }
        cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";
    }


    return 0;
}
