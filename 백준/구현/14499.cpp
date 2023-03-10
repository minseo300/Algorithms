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

int n,m,x,y,k;
int map[20][20];
struct Node{
    int y,x;
};
int vert[3]={0,0,0}; // 서,위,동 - 4,1,3
int hor[4]={0,0,0,0}; // 뒤, 위, 앞, 밑 - 2,1,5,6
int order;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m>>y>>x>>k;
    Node now={y,x};
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>map[y][x];
            // if(map[y][x]==0){
            //     now.y=y;
            //     now.x=x;
            // }
        }
    }
    int dy,dx;
    int temp_vert[3],temp_hor[4];
    for(int i=0;i<k;i++){
        cin>>order;
        // cout<<"-order: "<<order<<"\n";
        memcpy(temp_hor,hor,sizeof(hor));
        memcpy(temp_vert,vert,sizeof(vert));
        int ignore=0;
        if(order==1){ // 동
            dy=now.y;
            dx=now.x+1;
            if(dy<0||dx<0||dy>=n||dx>=m) {
                ignore=1;
                continue;
            }
            vert[0]=temp_hor[3];
            vert[1]=temp_vert[0];
            vert[2]=temp_vert[1];
            hor[1]=temp_vert[0];
            hor[3]=temp_vert[2];
        }
        else if(order==2){ // 서
            dy=now.y;
            dx=now.x-1;
            if(dy<0||dx<0||dy>=n||dx>=m) {
                ignore=1;
                continue;
            }
            vert[0]=temp_vert[1];
            vert[1]=temp_vert[2];
            vert[2]=temp_hor[3];
            hor[1]=temp_vert[2];
            hor[3]=temp_vert[0];
        }
        else if(order==3){ // 북
            dy=now.y-1;
            dx=now.x;
            if(dy<0||dx<0||dy>=n||dx>=m) {
                ignore=1;
                continue;
            }
            hor[0]=temp_hor[1];
            hor[1]=temp_hor[2];
            hor[2]=temp_hor[3];
            hor[3]=temp_hor[0];
            vert[1]=temp_hor[2];
        }
        else if(order==4){ // 남
            dy=now.y+1;
            dx=now.x;
            if(dy<0||dx<0||dy>=n||dx>=m) {
                ignore=1;
                continue;
            }
            hor[0]=temp_hor[3];
            hor[1]=temp_hor[0];
            hor[2]=temp_hor[1];
            hor[3]=temp_hor[2];
            vert[1]=temp_hor[0];
        }

        if(map[dy][dx]==0){
            map[dy][dx]=hor[3];
        }
        else{
            hor[3]=map[dy][dx];
            map[dy][dx]=0;
        }
        // cout<<"ignore: "<<ignore<<"\n";
        if(ignore!=1){
            cout<<hor[1]<<"\n";
            now.y=dy;
            now.x=dx;
            // cout<<dy<<" "<<dx<<"\n";
            // cout<<now.y<<" "<<now.x<<" "<<order<<"\n";

        } 
        
    }

    return 0;
}
