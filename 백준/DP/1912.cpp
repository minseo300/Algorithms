#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
long long arr[100000];
long long dp[100000];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];

    dp[0]=arr[0];
    long long maxi=dp[0];
    for(int i=1;i<n;i++){
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
        if(dp[i]>maxi) maxi=dp[i];
    }

    cout<<maxi<<"\n";

	return 0;
}