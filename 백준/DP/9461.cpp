#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int tc;
    cin>>tc;
    long long dp[101]={0L,1L,1L,};
    for(int i=0;i<tc;i++){
        int n;
        cin>>n;
        for(int j=3;j<=n;j++) dp[j]=dp[j-3]+dp[j-2];
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}