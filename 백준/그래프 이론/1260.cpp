#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,v;
int map[1001][1001]={0,};
int used[1001]={0,};
queue<int> q;
void initialize(){
    for(int i=0;i<1001;i++) used[i]=0;
}
void dfs(int now){
    cout<<now<<" ";
    for(int i=1;i<1001;i++){
        if(map[now][i]==0) continue;
        if(used[i]==1) continue;

        used[i]=1;
        dfs(i);
    }
}
void bfs(int now){
    used[now]=1;
    q.push(now);
    
    while(!q.empty()){
        int p=q.front();
        q.pop();
        cout<<p<<" ";

        for(int i=1;i<1001;i++){
            if(map[p][i]==0) continue;
            if(used[i]==1) continue;

            used[i]=1;
            q.push(i);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n>>m>>v;
    
    for(int i=0;i<m;i++){
        int p1,p2;
        cin>>p1>>p2;
        map[p1][p2]=1;
        map[p2][p1]=1;
    }

    // DFS
    used[v]=1;
    dfs(v);
    cout<<"\n";

    // BFS
    initialize();
    bfs(v);
    cout<<"\n";
    return 0;
}