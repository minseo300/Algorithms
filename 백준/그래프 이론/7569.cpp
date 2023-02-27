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
int map[100][100][100];
int dz[6]={0,0,0,0,-1,1};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={-1,1,0,0,0,0};
int used[100][100][100];
struct Node{
    int z,y,x;
};
queue<Node> q;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int m,n,h;
    cin>>m>>n>>h;


    for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for(int k = 0; k < m ; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({i,j,k });
				}
				if (map[i][j][k] == 0)
					used[i][j][k] = -1;
			}
		}
	}

    while(!q.empty()){
        Node now=q.front();
        q.pop();

        for(int d=0;d<6;d++){
            int nz=now.z+dz[d];
            int ny=now.y+dy[d];
            int nx=now.x+dx[d];

            if(nz<0||ny<0||nx<0||nz>=h||ny>=n||nx>=m) continue;
            if(used[nz][ny][nx]>=0) continue;

            q.push({nz,ny,nx});
            used[nz][ny][nx]=used[now.z][now.y][now.x]+1;
        }
    }
    int ans=-21e8;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                
                if(used[i][j][k]==-1){
                    cout<<"-1";
                    return 0;
                }
                ans=max(ans,used[i][j][k]);
            }
        }
    }
    cout<<ans<<"\n";


    return 0;
}