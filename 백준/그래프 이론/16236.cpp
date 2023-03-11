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

int n;
int map[21][21];
struct Node{
    int y,x,cnt;
};
// Node shark;
int visited[21][21];
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int sY,sX,sS;
int ans=0;
bool compare(Node t,Node v){
    if(t.cnt==v.cnt){
        if(t.y==v.y) return t.x<v.x;
        else return t.y<v.y;
    }
    return t.cnt<v.cnt;
}
Node bfs(int y, int x){
    queue<Node> q;
    memset(visited,0,sizeof(visited));

    q.push({y,x,0});
    visited[y][x]=1;
    vector<Node> canEat;
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        // printf("now: %d %d %d\n",now.y,now.x,now.cnt);
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=n) continue;
            if(visited[dy][dx]==1) continue;
            if(map[dy][dx]>sS) continue;

            if(map[dy][dx]>0&&map[dy][dx]<sS) {
                canEat.push_back({dy,dx,now.cnt+1});
            }
            visited[dy][dx]=1;
            q.push({dy,dx,now.cnt+1});
        }
    }
    if(canEat.size()==0){
        return {-1,-1,-1};
    }
    
    sort(canEat.begin(),canEat.end(),compare);
    return canEat[0];
    
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
            if(map[y][x]==9){
                sY=y;
                sX=x;
                map[y][x]=0;
            }
        }
    }
    sS=2;
    int eatCnt=0;
    while(true){
        Node ret=bfs(sY,sX);
        // printf("ret: %d %d %d\n",ret.y,ret.x,ret.cnt);
        if(ret.y==-1&&ret.x==-1&&ret.cnt==-1) break;
        else{
            map[ret.y][ret.x]=0;
            ans+=ret.cnt;
            eatCnt++;
            if(eatCnt==sS) {
                sS++;
                eatCnt=0;
            }
            sY=ret.y;
            sX=ret.x;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
