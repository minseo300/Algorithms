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
vector<vector<int>> map(201);
vector<int> plan;
int visited[201];
void bfs(){
    queue<int> q;
    visited[plan[0]]=1;
    q.push(plan[0]);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<map[now].size();i++){
            int next=map[now][i];
            if(visited[next]==1) continue;
            q.push(next);
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
    cin>>n>>m;
    int pos=0;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin>>pos;
            if(pos==1) {
                map[y].push_back(x);
                map[x].push_back(y);
            }
        }
    }
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        plan.push_back(num);
    }
    bfs();
    for(int i=0;i<m;i++){
        if(visited[plan[i]]==0){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}