#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int> dp;
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    dp.assign(n+1,21e8);

    dp[1]=0;
    for(int i=1;i<=n;i++){
        int p1=i*3;
        int p2=i*2;
        int p3=i+1;

        if(p1<=n) dp[p1]=min(dp[p1],dp[i]+1);
        if(p2<=n) dp[p2]=min(dp[p2],dp[i]+1);
        if(p3<=n) dp[p3]=min(dp[p3],dp[i]+1);
    }
    
    cout<<dp[n]<<"\n";
    return 0;
}