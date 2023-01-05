#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin>>n;

    vector<vector<int> > map;

    for(int i=0;i<n;i++){
        vector<int> rgb(3,0);
        cin>>rgb[0]>>rgb[1]>>rgb[2];
        map.push_back(rgb);
    }

    int dp[3]={map[0][0],map[0][1],map[0][2]};

    for(int i=1;i<n;i++){
        int r=min(dp[1],dp[2])+map[i][0];
        int g=min(dp[0],dp[2])+map[i][1];
        int b=min(dp[0],dp[1])+map[i][2];
        dp[0]=r; dp[1]=g; dp[2]=b;
    }
    sort(dp,dp+3);
    cout<<dp[0]<<"\n";
    return 0;
}