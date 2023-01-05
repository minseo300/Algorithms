#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int dp[501]={0,};
int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n;
    vector<vector<int> > map;
    for(int i=0;i<n;i++){
        vector<int> line(i+1);
        for(int j=0;j<=i;j++){
            cin>>line[j];
        }
        map.push_back(line);
    }
    dp[0]=map[0][0];
    int maxi=dp[0];
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(j==i) dp[j]=dp[j-1]+map[i][j];
            else if(j==0) dp[j]=dp[j]+map[i][j];
            else dp[j]=max(dp[j-1],dp[j])+map[i][j];

            if(maxi<dp[j]) maxi=dp[j];
        }
    }
    cout<<maxi<<"\n";
    return 0;
}