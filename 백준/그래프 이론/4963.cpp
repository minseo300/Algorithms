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
int used[50][50];
int direct[8][2]={
    -1,-1,
    -1,0,
    -1,1,
    0,-1,
    0,1,
    1,-1,
    1,0,
    1,1
};
struct Node{
    int y,x;
};
queue<Node> q;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int w,h;
    while(true){
        cin>>w>>h;
        // cout<<"w: "<<w<<" h: "<<h<<"\n";
        if(w==0&&h==0) break;

        // 지도 입력; 0 - 바다 / 1 - 땅
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                cin>>map[y][x];
            }
        }

        memset(used,0,sizeof(used));
        int cnt=0;
         for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                // printf("map[%d][%d]: %d\n",y,x,map[y][x]);
                if(used[y][x]==1) continue;
                if(map[y][x]==0) continue;

                q.push({y,x});
                while(!q.empty()){
                    Node now=q.front();
                    q.pop();

                    for(int d=0;d<8;d++){
                        int dy=now.y+direct[d][0];
                        int dx=now.x+direct[d][1];

                        if(dy<0||dx<0||dy>=h||dx>=w) continue;
                        if(used[dy][dx]==1) continue;

                        if(map[dy][dx]==1){
                            used[dy][dx]=1;
                            q.push({dy,dx});
                        }
                    }
                }
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}