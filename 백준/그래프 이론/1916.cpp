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
struct Node{
    int n,price;
};
vector<vector<Node>> map(1001);
priority_queue<Node> q;
bool operator<(Node v,Node t){
    return t.price<v.price;
}
int result[1001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) result[i]=M;

    for(int i=0;i<m;i++){
        int s,e,p;
        cin>>s>>e>>p;

        map[s].push_back({e,p});
    }
    int arr,dep;
    cin>>arr>>dep;

    q.push({arr,0});

    while(!q.empty()){
        Node now=q.top();
        q.pop();
        
        if(result[now.n]<now.price) continue;

        for(int i=0;i<map[now.n].size();i++){
            Node next=map[now.n][i];

            int total=now.price+next.price;

            if(result[next.n]>total){
                result[next.n]=total;
                q.push({next.n,total});
            }
        }
    }

    cout<<result[dep]<<"\n";
	return 0;
}