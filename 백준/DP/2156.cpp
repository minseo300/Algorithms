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

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    vector<int> j(n+1);
    for(int i=1;i<=n;i++){
        cin>>j[i];
    }
    vector<int> dp(n+1);
   dp[1]=j[1];
   dp[2]=j[1]+j[2];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-1],max(dp[i-3]+j[i-1]+j[i],dp[i-2]+j[i]));
        // ans=max(ans,dp[i]);
    }
    cout<<dp[n]<<"\n";
	return 0;
}