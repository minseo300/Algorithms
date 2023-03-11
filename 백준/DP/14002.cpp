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

int arr[1001];
int dp[1001];
vector<int> lis[1001];
vector<int> answer;
int n;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        dp[i]=1;
        lis[i].push_back(arr[i]);
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                if(dp[i]<dp[j]+1){
                    lis[i].clear();
                    lis[i]=lis[j];
                    lis[i].push_back(arr[i]);
                    dp[i]=dp[j]+1;
                }
            }
        }
        if(answer.size()<lis[i].size()){
            answer=lis[i];
        }
    }
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
