#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
long long dp[1001]={0L,};
int dp2[1001]={0,};
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin>>n;

    dp[1]=1;
    dp[2]=2;
    
    
    dp2[1]=1;
    dp2[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
        dp2[i]=dp2[i-1]+dp[i-2];
    }
    cout<<dp[n]<<"\n";
    return 0;
}