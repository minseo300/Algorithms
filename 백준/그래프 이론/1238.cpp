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

#define M 21e8
int result[1001];
int n,m,x;
struct Node{
    int n,time;
};
vector<vector<Node>> map(10001);

bool operator<(Node v,Node t){
    return t.time<v.time;
}
int dijkstra(int a,int d){

    for(int k=0;k<=n;k++) result[k]=M;
    priority_queue<Node> q;

    q.push({a,0});
    result[a]=0;
    while(!q.empty()){
        Node now=q.top();
        q.pop();

        if(result[now.n]<now.time) continue;

        for(int i=0;i<map[now.n].size();i++){
            Node next=map[now.n][i];

            int total=now.time+next.time;
            if(result[next.n]>total){
                result[next.n]=total;
                q.push({next.n,total});
            }
        }
    }
    return result[d];
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m>>x;
    for(int i=0;i<=n;i++) {
        go[i]=M;
        back[i]=M;
        result[i]=M;
    }

    for(int i=0;i<m;i++){
        int s,e,t;
        cin>>s>>e>>t;
        map[s].push_back({e,t});
    }
    int answer=-1;
    for(int i=1;i<=n;i++){
        int itoX=dijkstra(i,x);
        int xtoI=dijkstra(x,i);
        answer=max(answer,itoX+xtoI);
    }


    cout<<answer<<"\n";

	return 0;
}