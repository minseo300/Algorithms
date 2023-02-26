#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
#define M 21e8
#define MAX 20010
using namespace std;

struct Node{
    int n,price;
};
bool operator<(Node v,Node t){
    return t.price<v.price;
}
vector<vector<Node>> map(MAX);
int result[MAX];
priority_queue<Node> q;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int v,e,k; //  정점 개수, 간선 개수, 시작 지점
    cin>>v>>e>>k;

    for(int i=0;i<=v;i++) result[i]=M;
    result[k]=0;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back({v,w});
        // if(u==k) q.push({u,w});
    }
    q.push({k,0});
    while(!q.empty()){
        Node now=q.top();
        q.pop();
        // cout<<"[now] n: "<<now.n<<" price: "<<now.price<<"\n";
        if(result[now.n]<now.price) continue;

        for(int i=0;i<map[now.n].size();i++){
            Node next=map[now.n][i];
            // cout<<"[next] n: "<<next.n<<" price: "<<next.price<<"\n";
           int total=now.price+next.price;
        //    printf("result[%d]: %d total: %d\n",next.n, result[next.n],total);
           if(result[next.n]>total){
            result[next.n]=total;
            q.push({next.n,total});
           }
        }
    }
    for(int i=1;i<=v;i++){
        if(result[i]==M) cout<<"INF\n";
        else cout<<result[i]<<"\n";
    }
	return 0;
}