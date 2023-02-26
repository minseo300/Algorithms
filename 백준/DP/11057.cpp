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
int dp[1001][10];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    for(int i=0;i<10;i++) dp[1][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
            }
        }
    }
   
    long long ans=0;
    for(int i=0;i<10;i++) ans=(ans+dp[n][i])%10007;

    cout<<ans<<"\n";
	return 0;
}