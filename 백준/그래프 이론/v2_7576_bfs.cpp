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

int m,n; // 가로, 세로
int map[1000][1000];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
struct Node{
    int y,x,cnt;
};
int rotten=0;
int not_rotten=0;
int not_exist=0;
int visited[1000][1000];
queue<Node> q;
int ans=21e8;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>m>>n;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>map[y][x];
            if(map[y][x]==1) {
                rotten++;
                q.push({y,x,0});
                visited[y][x]=1;
            }
            else if(map[y][x]==0) not_rotten++;
            else if(map[y][x]==-1) not_exist++;
        }
    }
    if(rotten+not_exist==n*m) {
        cout<<"0\n";
    }
    else{
        while(!q.empty()){
            Node now=q.front();
            q.pop();
            ans=now.cnt;
            for(int d=0;d<4;d++){
                int dy=now.y+diry[d];
                int dx=now.x+dirx[d];

                if(dy<0||dx<0||dy>=n||dx>=m) continue;
                if(visited[dy][dx]==1) continue;
                if(map[dy][dx]!=0) continue;

                q.push({dy,dx,now.cnt+1});
                visited[dy][dx]=1;
                not_rotten--;
                rotten++;
            }
        }
        if(rotten+not_exist==n*m) cout<<ans<<"\n";
        else if(rotten+not_exist<n*m) cout<<"-1\n";
    }
    return 0;
}
