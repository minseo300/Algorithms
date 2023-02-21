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
int map[50][50];
int visited[50][50];
struct Node{
    int y,x;
};
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

    ////////////////////// 입력
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
        int m,n,k,answer=0; // x,y
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        queue<Node> q;
        cin>>m>>n>>k;
        for(int i=0;i<k;i++){
            int y,x;
            cin>>x>>y;
            map[y][x]=1;
        }
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if(map[y][x]==1&&visited[y][x]==0){
                    q.push({y,x});
                    visited[y][x]=1;
                    while(!q.empty()){
                        Node now=q.front();
                        q.pop();
                        for(int d=0;d<4;d++){
                            int dy=now.y+direct[d][0];
                            int dx=now.x+direct[d][1];

                            if(dy<0||dx<0||dy>=n||dx>=m) continue;
                            if(visited[dy][dx]==1) continue;
                            if(map[dy][dx]==0) continue;

                            q.push({dy,dx});
                            visited[dy][dx]=1;
                        }
                    }
                    answer++;
                }
            }
        }
        cout<<answer<<"\n";
    }

	return 0;
}