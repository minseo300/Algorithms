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
    int arr[1001];
    int dp[1001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=arr[i];
        for(int j=1;j<=i;j++){
            if(arr[j]<arr[i]&&dp[i]<dp[j]+arr[i]) {
                dp[i]=arr[i]+dp[j];
            }
        }
        ans=max(ans,dp[i]);

    }
    cout<<ans<<"\n";
    

    return 0;
}