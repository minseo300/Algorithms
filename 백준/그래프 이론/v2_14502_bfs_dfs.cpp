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

int n,m; // 세로, 가로
int map[8][8];
struct Node{
    int y,x;
};
int visited_wall[8][8];
int visited[8][8];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
Node wall[3];
int bfs(){
    int temp[8][8];
    memcpy(temp,map,sizeof(map));
    for(int i=0;i<3;i++){
        temp[wall[i].y][wall[i].x]=1;
    }
    
    memset(visited,0,sizeof(visited));
    queue<Node> q;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(temp[y][x]==2){
                q.push({y,x});
                visited[y][x]=1;
            } 
        }
    }
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        // printf("map[%d][%d]: %d\n",now.y,now.x,map[now.y][now.x]);
        for(int d=0;d<4;d++){
            int dy=diry[d]+now.y;
            int dx=dirx[d]+now.x;

            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(temp[dy][dx]!=0) continue;
            if(visited[dy][dx]==1) continue;

            q.push({dy,dx});
            visited[dy][dx]=1;
            temp[dy][dx]=2;
        }
    }
    int ret=0;
    // for(int y=0;y<n;y++){
    //     for(int x=0;x<m;x++){
    //         cout<<temp[y][x]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(temp[y][x]==0) ret++;
        }
    }
    return ret;
}
int ans=-21e8;
void dfs(int lev){
    if(lev==3){
        int ret=bfs();
        ans=max(ans,ret);
        return;
    }

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(visited_wall[y][x]==1) continue;
            if(map[y][x]!=0) continue;

            wall[lev]={y,x};
            visited_wall[y][x]=1;
            dfs(lev+1);
            visited_wall[y][x]=0;
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
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>map[y][x];
        }
    }
    dfs(0);
    cout<<ans<<"\n";
    return 0;
}
