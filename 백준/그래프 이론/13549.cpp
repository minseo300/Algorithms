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

#define M 21e8;
#define MAX 100001
int result[100001];
struct Node{
    int n,time;
};
priority_queue<Node> q;
bool operator<(Node v,Node t){
    return t.time<v.time;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n,k;
    cin>>n>>k;
    for(int i=0;i<100001;i++) result[i]=M;

    q.push({n,0});

    while(!q.empty()){
        Node now=q.top();
        q.pop();

        if(result[now.n]<now.time) continue;

        // 순간이동
        if(now.n*2<MAX&&now.time<result[now.n*2]){
            result[now.n*2]=now.time;
            q.push({now.n*2,now.time});
        }
        // 걷기 X+1
        if(now.n+1<MAX&&now.time+1<result[now.n+1]){
            result[now.n+1]=now.time+1;
            q.push({now.n+1,now.time+1});
        }
        // 걷기 X-1
        if(now.n-1>=0&&now.time+1<result[now.n-1]){
            result[now.n-1]=now.time+1;
            q.push({now.n-1,now.time+1});
        }
    }

    if(n>=k) cout<<n-k<<"\n";
    else cout<<result[k]<<"\n";


	return 0;
}