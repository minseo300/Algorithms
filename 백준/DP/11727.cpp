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
int dp[1001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    dp[1]=1; 
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
    }
    cout<<dp[n]<<"\n";
	return 0;
}