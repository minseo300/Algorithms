#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,rotten=0,notrotten=0,mini;
vector<vector<int> > map;
vector<vector<int> > used;
struct Node{
    int y,x;
};
queue<Node> q;
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>m>>n;
    map.assign(n,vector<int>(m,0));
    used.assign(n,vector<int>(m,0));

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++) {
            cin>>map[y][x];
            if(map[y][x]==1){
                Node node={y,x};
                q.push(node);
            }
        }
    }
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(map[dy][dx]!=0) continue;

            Node next={dy,dx};
            q.push(next);
            map[dy][dx]=map[now.y][now.x]+1;
        }       
    }
    int ans=0;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(map[y][x]==0) {
                cout<<"-1\n"; return 0;
            }
            if(ans<map[y][x]) ans=map[y][x];
        }
    }
    cout<<ans-1<<"\n";


	return 0;
}