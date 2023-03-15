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
struct Node{
    int y,x,wall;
};
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
int visited[1001][1001][2];
int map[1001][1001];
queue<Node> q;
int bfs(int y,int x){
    q.push({y,x,0});
    visited[y][x][0]=1;

    while(!q.empty()){
        Node now=q.front();
        q.pop();
        if(now.y==n&&now.x==m) return visited[now.y][now.x][now.wall];

        for(int d=0;d<4;d++){
            int dy=now.y+diry[d];
            int dx=now.x+dirx[d];

            if(dy<1||dx<1||dy>n||dx>m) continue;

            if(map[dy][dx]==1&&now.wall==0){
                visited[dy][dx][1]=visited[now.y][now.x][0]+1;
                q.push({dy,dx,1});
            }
            if(map[dy][dx]==0&&visited[dy][dx][now.wall]==0){
                visited[dy][dx][now.wall]=visited[now.y][now.x][now.wall]+1;
                q.push({dy,dx,now.wall});
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
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            map[i][j]=s[j-1]-'0';
        }
    }
    cout<<bfs(1,1);
    return 0;
}
