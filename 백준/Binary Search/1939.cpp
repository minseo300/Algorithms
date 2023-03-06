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

int n,m; // 섬의 개수, 다리 개수
int k,l;
struct Node{
    int is,cost;
};
vector<vector<Node>> map(10001);
vector<int> costs;
int visited[10001];

int bfs(int cost){
    queue<int> q;
    memset(visited,0,sizeof(visited));
    // for(int i=0;i<10002;i++) visited[i]=0;
    q.push(k);
    visited[k]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(now==l) return 1;
        for(int i=0;i<map[now].size();i++){
            Node next=map[now][i];
            if(visited[next.is]==1) continue;

            if(next.cost>=cost){ // 현재 섬에서 다른 섬으로 넘어갈 때, 더 큰 중량을 가져갈 수 있는 섬에 대해서만 push
                q.push(next.is);
                visited[next.is]=1;
            }
        }        
    }
    return 0;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    // cout<<n<<" "<<m<<"\n";
    int s=0, e=-21e8;

    for(int i=0;i<m;i++){
        int a,b,c; // a번 섬과 b번 섬 사이에 중량제한이 c인 다리가 존재.
        cin>>a>>b>>c;
        map[a].push_back({b,c});
        map[b].push_back({a,c});
        if(c>e) e=c;
    }
    cin>>k>>l;
    int ret=-21e8;
    while(s<=e){
        int mid=(s+e)/2; // 가져갈 수 있는 중량 제한 후보
        if(bfs(mid)){
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<e<<"\n";


    return 0;
}