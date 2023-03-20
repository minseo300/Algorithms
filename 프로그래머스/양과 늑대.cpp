#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
vector<vector<int>> map(18);

int answer = 0;

vector<int> info_;
void dfs(int node,int sheep,int wolf,queue<int> q){
    cout<<node<<"\n";
    if(info_[node]==0) sheep++;
    else wolf++;
    
    if(wolf>=sheep) return;
    if(answer<sheep) answer=sheep;
    
    for(int i=0;i<map[node].size();i++){
       q.push(map[node][i]);
    }
    
    for(int i=0;i<q.size();i++){
        int next=q.front();
        q.pop();
        dfs(next,sheep,wolf,q);
        q.push(next);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(int i=0;i<edges.size();i++){
        map[edges[i][0]].push_back(edges[i][1]);
    }
    info_.assign(info.begin(),info.end());
    queue<int> q;
    dfs(0,0,0,q);
    return answer;
}