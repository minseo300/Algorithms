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
int map[50][50];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
int used[50][50];
struct Node{
    int y,x,cnt;
};
int bfs(int y,int x){
    memset(used,0,sizeof(used));
    used[y][x]=1;
    queue<Node> q;
    q.push({y,x,0});
    int dis=-21e8;
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        dis=now.cnt;
        for(int d=0;d<4;d++){
            int dy=now.y+diry[d];
            int dx=now.x+dirx[d];

            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(used[dy][dx]==1) continue;
            if(map[dy][dx]==0) continue;

            q.push({dy,dx,now.cnt+1});
            used[dy][dx]=1;
        }
    }
    return dis;
}
int ans=-21e8;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int y=0;y<n;y++){
        string s;
        cin>>s;
        for(int x=0;x<m;x++){
            if(s[x]=='L') map[y][x]=1; // 육지
            else map[y][x]=0; // 바다
        }
    }

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(map[y][x]==1){
                ans=max(ans,bfs(y,x));
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}