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
int dp[31][31];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++) dp[1][i]=i;

        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++)
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
        }
        cout<<dp[n][m]<<"\n";

    }


    
	return 0;
}