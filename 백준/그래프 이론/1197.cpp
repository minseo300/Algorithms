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

int v,e; // 정점의 개수, 간선의 개수
struct Node{
    int node,cost;
};
bool operator<(Node v,Node t){
    return t.cost<v.cost;
}
priority_queue<Node> q;
long long ret;
vector<vector<Node>> map(10001);

int visited[10001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int a,b,c; // a정점과 b정점이 가중치 c인 간선으로 연결됨
        cin>>a>>b>>c;
        map[a].push_back({b,c});
        map[b].push_back({a,c});
    }
    q.push({1,0});
    
    while(!q.empty()){
        Node now=q.top();
        // cout<<"[now] - node: "<<now.node<<" cost: "<<now.cost<<"\n";
        q.pop();


        // cout<<"ret: "<<ret<<"\n";
        if(visited[now.node]==1) continue;

        visited[now.node]=1;
        ret+=now.cost;

        for(int i=0;i<map[now.node].size();i++){
            Node next=map[now.node][i];
            // cout<<"[next] - node: "<<next.node<<" cost: "<<next.cost<<"\n";

            q.push(next);
        }
    }

    cout<<ret<<"\n";
    return 0;
}