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
    int v,w;
};
bool operator<(Node v,Node t){
    return t.w<v.w;
}
int v,e; // 정점, 간선 개수
int k; // 시작 정점
int ret[20001];
vector<vector<Node>> map(20001);
priority_queue<Node> q;
void dijkstra(int start){
    ret[start]=0;
    q.push({start,0});

    while(!q.empty()){
        Node now=q.top();
        q.pop();

        for(int i=0;i<map[now.v].size();i++){
            Node next=map[now.v][i];

            if(ret[now.v]<now.w) continue;
            int total=now.w+next.w;
            if(total<ret[next.v]){
                ret[next.v]=total;
                q.push({next.v,total});
            }
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>v>>e;
    cin>>k;
    for(int i=1;i<v+1;i++){
        ret[i]=21e8;
    }
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back({v,w});
    }
    dijkstra(k);
    for(int i=1;i<v+1;i++){
        if(ret[i]==21e8) cout<<"INF\n";
        else cout<<ret[i]<<"\n"; 
    }
    return 0;
}
