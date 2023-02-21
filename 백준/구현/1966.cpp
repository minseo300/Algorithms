#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;
struct Node{
    int importance,index;
};
bool operator<(Node v,Node t){
    return t.importance>v.importance;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int n,m;
        cin>>n>>m;
        queue<Node> q;
        priority_queue<Node> pq;
        int answer=0,answer_imp=0;
        for(int j=0;j<n;j++){
            int imp;
            cin>>imp;
            q.push({imp,j});
            pq.push({imp,j});
            if(j==m) answer_imp=imp;
        }

        while(true){
            Node now=q.front();
            q.pop();
            Node first=pq.top();
            if(now.importance>=first.importance) {
                pq.pop();
                answer++;
            }
            if(now.index==m&&now.importance==first.importance) break;
           
            if(now.importance<first.importance) q.push(now);
            
        }
        cout<<answer<<"\n";
    }

	return 0;
}