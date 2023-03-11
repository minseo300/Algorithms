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

int n,m;
vector<vector<int>> arr(32001);
int inDegree[32001]={0,};
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        cout<<now<<" ";
        for(int i=0;i<arr[now].size();i++){
            int next=arr[now][i];
            inDegree[next]--;
            if(inDegree[next]==0) q.push(next);
        }
    }
    return 0;
}
