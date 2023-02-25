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
    int dp[41]={0,1,1};
    for(int i=3;i<41;i++) dp[i]=dp[i-1]+dp[i-2];
    int t;
    cin>>t;
    for(int i=0;i<t;i++){ 
        int n;
        cin>>n;
        if(n==0) cout<<"1 0\n";
        else if(n==1) cout<<"0 1\n";
        else cout<<dp[n-1]<<" "<<dp[n]<<"\n";
    }
    
	return 0;
}