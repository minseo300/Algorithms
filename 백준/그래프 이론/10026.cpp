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
int map[100][100]; // 적록색약 아닌 경우
int map2[100][100]; // 적록색약인 경우
int used[100][100];
struct Node{
    int y,x,color;
};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int floodfill(int area[100][100]){
    int cnt=0;
    memset(used,0,sizeof(used));
    queue<Node> q;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(used[y][x]==1) continue;

            q.push({y,x,area[y][x]});
            while(!q.empty()){
                Node now=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int dy=now.y+direct[d][0];
                    int dx=now.x+direct[d][1];

                    if(dy<0||dx<0||dy>=n||dx>=n) continue;
                    if(used[dy][dx]==1) continue;

                    if(area[dy][dx]==now.color){
                        used[dy][dx]=1;
                        q.push({dy,dx,area[dy][dx]});

                    } 
                }
            }
            cnt++;
        }
    }

    return cnt;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='R') {
                map[i][j]=1;
                map2[i][j]=1;
            }
            else if(s[j]=='G') {
                map[i][j]=2;
                map2[i][j]=1;
            }
            else if(s[j]=='B') {
                map[i][j]=3;
            }
        }
    }
    
    // 적록색약이 아닌 사람
    int normal=floodfill(map);
    
    // 적록색약인 사람
    int not_normal=floodfill(map2);
    cout<<normal<<" "<<not_normal<<"\n";
	return 0;
}