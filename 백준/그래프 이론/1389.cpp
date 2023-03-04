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
vector<vector<int>> map(120);
queue<int> q;
struct Node{
    int idx,sum;
};
bool compare(Node t,Node v){
    if(t.sum==v.sum) return t.idx<v.idx;

    return t.sum<v.sum;
}
int used[102][102]; // y,x -> y번 유저는 x번 유저와 used[y][x] 단계이다.
void bfs(int p){
    q.push(p);
    int visited[102]={0,};

    visited[p]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();

        for(int i=0;i<map[now].size();i++){
            int next=map[now][i];

            if(visited[next]==1) continue;

            q.push(next);
            used[next][p]=used[now][p]+1;
            used[p][next]=used[p][now]+1;
            visited[next]=1;
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m; // 유저 수, 친구 관계 수
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        bfs(i);
    }
    vector<Node> sums;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=used[i][j];
        }
        sums.push_back({i,sum});
        // cout<<"\n";
    }
    sort(sums.begin(),sums.end(),compare);
    cout<<sums[0].idx;
    return 0;
}