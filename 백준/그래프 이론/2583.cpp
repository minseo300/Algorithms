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

int m,n,k; // 세로, 가로
int map[101][101],used[101][101];
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
vector<int> area;
struct Node{
    int y,x;
};
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        for(int y=x1;y<x2;y++){
            for(int x=y1;x<y2;x++){
                // cout<<x<<" "<<y<<"\n";
                map[y][x]=1;
            }
        }
        // cout<<"\n";
    }

    queue<Node> q;
   
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            if(map[y][x]==0&&used[y][x]==0){
                q.push({y,x});
                used[y][x]=1;
                int cnt=1;
                while(!q.empty()){
                    Node now=q.front();
                    q.pop();
                    // printf("now y:%d x:%d\n",now.y,now.x);
                    for(int d=0;d<4;d++){
                        int dy=now.y+direct[d][0];
                        int dx=now.x+direct[d][1];

                        if(dy<0||dx<0||dy>=n||dx>=m) continue;
                        if(used[dy][dx]==1) continue;
                        if(map[dy][dx]==1) continue;

                        used[dy][dx]=1;
                        q.push({dy,dx});
                        cnt++;
                    }
                }
                // cout<<"cnt: "<<cnt<<"\n";
                area.push_back(cnt);
            }
        }
    }
    sort(area.begin(),area.end());
    cout<<area.size()<<"\n";
    for(int i=0;i<area.size();i++){
        cout<<area[i]<<" ";
    }
    return 0;
}