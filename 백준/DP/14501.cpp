#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// int dp[16]={0,};
int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;

   
    int t[16],p[16];
    vector<int> dp(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }

    for(int i=n;i>0;i--){
        if(i+t[i]>n+1) dp[i]=dp[i+1];

        else dp[i]=max(dp[i+1],dp[i+t[i]]+p[i]);
    }

    cout<<dp[1]<<"\n";
    return 0;
}