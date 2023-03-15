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
struct Node{
    int node,cost;
};
bool operator<(Node v, Node t){
    return t.cost<v.cost;
}
priority_queue<Node> q;
vector<vector<Node>> map(1001);
int ret[1001];
int arrive,depart;
void dijkstra(int s){
    ret[s]=0;
    q.push({s,0});

    while(!q.empty()){
        Node now=q.top();
        q.pop();

        if(ret[now.node]<now.cost) continue;
        for(int i=0;i<map[now.node].size();i++){
            Node next=map[now.node][i];
            
            int total=next.cost+now.cost;
            if(ret[next.node]>total){
                ret[next.node]=total;
                q.push({next.node,total});
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
    cin>>n>>m;
    for(int i=1;i<=n;i++) ret[i]=21e8;
    for(int i=0;i<m;i++){
        int a,d,c;
        cin>>a>>d>>c;
        map[a].push_back({d,c});
    }
    cin>>arrive>>depart;
    dijkstra(arrive);
    cout<<ret[depart]<<"\n";
    return 0;
}
