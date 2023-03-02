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
struct Node{
    int start,end;
};
vector<Node> map;
bool compare(Node t,Node v){
    return t.start<v.start;
}
int dp[101];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        map.push_back({s,e});
    }
    sort(map.begin(),map.end(),compare);
    int longest=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(map[i].end>map[j].end){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        longest=max(longest,dp[i]);
    }
    cout<<n-longest<<"\n";

    return 0;
}