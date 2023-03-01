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
    cin>>n;
    int dp[100001];

    for(int i=1;i<=n;i++){
        dp[i]=i;
        for(int j=1;j*j<=i;j++) 
            dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    
    cout<<dp[n]<<"\n";

    return 0;
}