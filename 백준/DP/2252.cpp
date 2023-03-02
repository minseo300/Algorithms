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

int dp[201][201];
int n,k;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    for(int i=0;i<=k;i++) dp[1][i]=i; // i개로 1을 만드는 갯수 ex) 3개로 1을 만들 때 -> 1,0,0 / 0,1,0 / 0,0,1

    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            // i를 j개로 만드는 경우의 수
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000000;
        }
    }
    cout<<dp[n][k]<<"\n";
    return 0;
}