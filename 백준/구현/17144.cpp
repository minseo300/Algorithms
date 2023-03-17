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

int r,c,t;
int map[51][51];
// vector<vector<int>> map(51);
int temp[51][51];
struct Node{
    int y,x,quan;
};
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
Node cleaner[2];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>r>>c>>t;
    int idx=0;
    int ans=0;
    for(int y=0;y<r;y++){
        for(int x=0;x<c;x++){
            // int nn;
            // cin>>nn;
            cin>>map[y][x];
            // cout<<map[y][x];
            // map[y].push_back(nn);
            if(map[y][x]==-1) cleaner[idx++]={y,x,0};
            if(map[y][x]>0) ans+=map[y][x];
        }
    }
    // for(int y=0;y<r;y++){
    //     for(int x=0;x<c;x++){
    //         cout<<map[y][x]<<" ";
    //     }
    //     cout<<"\n";
    // }
    queue<Node> q;
    
    for(int i=0;i<t;i++){
        // 1. 미세먼지 확산
        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                if(map[y][x]>0){
                    q.push({y,x,map[y][x]});
                }
            }
        }
        while(!q.empty()){
            Node now=q.front();
            q.pop();
            int spread=0;
            for(int d=0;d<4;d++){
                int dy=now.y+diry[d];
                int dx=now.x+dirx[d];

                if(dy<0||dx<0||dy>=r||dx>=c) continue;
                if(map[dy][dx]==-1) continue;

                temp[dy][dx]+=now.quan/5;
                spread++;
            }
            map[now.y][now.x]-=now.quan/5*spread;
        }

        for(int y=0;y<r;y++){
            for(int x=0;x<c;x++){
                if(temp[y][x]>0){
                    map[y][x]+=temp[y][x];
                    temp[y][x]=0;
                }
            }
        }
        
        // 2. 공기청정기 작동
        ans-=map[cleaner[0].y-1][0];
        ans-=map[cleaner[1].y+1][0];
        // - 위쪽 공기청정기
        // 아래쪽 방향
        for(int i=cleaner[0].y-1;i>0;i--) map[i][0]=map[i-1][0];
        // 왼쪽 방향
        for(int i=0;i<c-1;i++) map[0][i]=map[0][i+1];
        // 위쪽 방향
        for(int i=1;i<=cleaner[0].y;i++) map[i-1][c-1]=map[i][c-1];
        // 오른쪽 방향
        for(int i=c-1;i>1;i--) map[cleaner[0].y][i]=map[cleaner[0].y][i-1];
        map[cleaner[0].y][1]=0;
        
        

        // - 아래쪽 공기청정기
        // 위쪽 방향
        for(int i=cleaner[1].y+1;i<r-1;i++) map[i][0]=map[i+1][0];
        // 왼쪽 방향
        for(int i=0;i<c-1;i++) map[r-1][i]=map[r-1][i+1];
        // 아래쪽 방향
        for(int i=r-1;i>=cleaner[1].y;i--) map[i][c-1]=map[i-1][c-1];
        // 오른쪽 방향
        for(int i=c-1;i>1;i--) map[cleaner[1].y][i]=map[cleaner[1].y][i-1];
        map[cleaner[1].y][1]=0;
    }
    cout<<ans;
    cout<<"\n";
    return 0;
}
