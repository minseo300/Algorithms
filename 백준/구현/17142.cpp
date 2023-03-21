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
int map[50][50];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
struct Node{
    int y,x,cnt;
};
Node path[11];
vector<Node> virus;
vector<Node> blank;
int visited[50][50];
int answer=21e8;
int spread(){
    int t=0,blank_size=blank.size();
    memset(visited,0,sizeof(visited));
    queue<Node> q;
    for(int i=0;i<m;i++){
        q.push({path[i].y,path[i].x,path[i].cnt});
        visited[path[i].y][path[i].x]=1;
    }
    while(!q.empty()){
        Node now=q.front();
        // printf("[now] y: %d x: %d cnt: %d\n",now.y,now.x,now.cnt);
        q.pop();

        for(int d=0;d<4;d++){
            int dy=now.y+diry[d];
            int dx=now.x+dirx[d];
            if(dy<0||dx<0||dy>=n||dx>=n) continue;
            if(visited[dy][dx]==1) continue;
            if(map[dy][dx]!=1){
                q.push({dy,dx,now.cnt+1});
                visited[dy][dx]=1;
                if(map[dy][dx]==0) {
                    blank_size--;
                    t=now.cnt+1;
                }
            }
        }
    }
    if(blank_size==0) return t;
    return -1;
}
void dfs(int idx,int lev){
    if(lev==m){
        int time=spread();
        if(time!=-1) answer=min(answer,time);
        return ;
    }

    for(int i=idx;i<virus.size();i++){
        path[lev]={virus[i].y,virus[i].x,virus[i].cnt};
        dfs(i+1,lev+1);
    }
    

}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++) {
            cin>>map[y][x];
            if(map[y][x]==2) virus.push_back({y,x,0});
            else if(map[y][x]==0) blank.push_back({y,x,0}); 
        }
    }

    dfs(0,0);
    if(answer==21e8) cout<<"-1\n";
    else cout<<answer<<"\n";
    return 0;
}