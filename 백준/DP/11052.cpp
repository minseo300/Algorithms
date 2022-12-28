#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int maxi=0,n;
int memo[1001]={0,};
int dp[1001]={0,};
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    int price[1001];
    vector<int> result(n+1,-21e8);
    for(int i=1;i<n+1;i++){
        cin>>price[i];
    }

    for(int i=1;i<n+1;i++){
        if(i==1) memo[i]=price[i];
        else{
            for(int j=1;j<=i;j++){
                int p=price[j]+memo[i-j];
                memo[i]=max(memo[i],p);
                
            }
        }
    }
    cout<<memo[n]<<"\n";
    
    return 0;
}