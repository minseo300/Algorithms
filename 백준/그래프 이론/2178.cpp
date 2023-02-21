#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;
int map[100][100];
int visited[100][100];
struct Node{
    int y,x,cnt;
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            map[i][j]=s[j]-'0';
        }
    }

    queue<Node> q;
    q.push({0,0,1});
    visited[0][0]=1;
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        int cnt;
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(map[dy][dx]==0) continue;
        
            if(visited[dy][dx]==0&&map[dy][dx]==1) {
                cnt=now.cnt+1;
                q.push({dy,dx,cnt});

            }
            else {
                cnt=min(now.cnt+1,map[dy][dx]);
            }
            map[dy][dx]=cnt;
            visited[dy][dx]=1;
            

        }
    }
    cout<<map[n-1][m-1]<<"\n";
	return 0;
}