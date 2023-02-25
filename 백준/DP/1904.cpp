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
long long dp[1000001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])%15746;
    }
    cout<<dp[n]%15746;
	return 0;
}