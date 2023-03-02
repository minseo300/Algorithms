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
int map[100000][3];
int dp[3];
int dp2[3];
int num[3];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    cin>>dp[0]>>dp[1]>>dp[2];
    dp2[0]=dp[0]; dp2[1]=dp[1]; dp2[2]=dp[2];
    for(int y=1;y<n;y++){
        cin>>num[0]>>num[1]>>num[2];

        int t0=dp[0]; int t1=dp[1]; int t2=dp[2];

        dp[0]=max(t0,t1)+num[0];
        dp[1]=max(t0,max(t1,t2))+num[1];
        dp[2]=max(t1,t2)+num[2];

        t0=dp2[0]; t1=dp2[1]; t2=dp2[2];

        dp2[0]=min(t0,t1)+num[0];
        dp2[1]=min(t0,min(t1,t2))+num[1];
        dp2[2]=min(t1,t2)+num[2];


    }
    

    int maxi=max(dp[0],max(dp[1],dp[2]));
    int mini=min(dp2[0],min(dp2[1],dp2[2]));

    cout<<maxi<<" "<<mini<<"\n";

    return 0;
}