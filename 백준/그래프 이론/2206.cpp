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
int map[1001][1001];
int visited[1001][1001][2];
struct Node{
    int y,x,wall;
};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int bfs(int y,int x){
    queue<Node> q;
    q.push({y,x,0});
    visited[y][x][0]=1; // 벽을 안 깬 상태로 방문
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        if(now.y==n-1&&now.x==m-1) return visited[now.y][now.x][now.wall];

        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=m) continue;

            if(map[dy][dx]==1 && now.wall==0){ // 벽으로 막혀있고 아직 안 깬 경우
                q.push({dy,dx,now.wall+1});
                visited[dy][dx][1]=visited[now.y][now.x][now.wall]+1;
            }
            else if(map[dy][dx]==0&&visited[dy][dx][now.wall]==0){ // 벽이 없고 방문하지 않았다면
                q.push({dy,dx,now.wall});
                visited[dy][dx][now.wall]=visited[now.y][now.x][now.wall]+1;
            }

        }
    }
    return -1;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='0') map[i][j]=0;
            else map[i][j]=1;
        }
    }
   
    cout<<bfs(0,0);
    return 0;
}