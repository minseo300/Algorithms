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
int n;
vector<vector<int>> map(100010);
int boss[100010];
int used[100010];
void dfs(int k){
    used[k]=1;
    for(int i=0;i<map[k].size();i++){
        int next=map[k][i];
        if(used[next]==1) continue;
        boss[next]=k;
        dfs(next);
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        cout<<boss[i]<<"\n";
    }
    return 0;
}