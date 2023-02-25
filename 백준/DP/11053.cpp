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
int nums[1000];
int dp[1000];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    dp[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
	return 0;
}