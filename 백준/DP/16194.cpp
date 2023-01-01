#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int cards[1001]={0,};
int dp[1001];
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    

    for(int i=1;i<n+1;i++) cin>>cards[i];
    for(int i=0;i<1001;i++) dp[i]=21e8;

    dp[0]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],dp[i-j]+cards[j]);
        }
    }

    cout<<dp[n]<<"\n";

    return 0;
}