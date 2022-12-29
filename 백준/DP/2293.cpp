#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k;
int coins[101];
int dp[10001]={0,};
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n>>k;
    
    for(int i=1;i<=n;i++) {
        cin>>coins[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=coins[i];j<=k;j++) dp[j]=dp[j]+dp[j-coins[i]];
    }

    cout<<dp[k]<<"\n";
    return 0;
}