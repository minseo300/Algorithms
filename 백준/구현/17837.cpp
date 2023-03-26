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

struct Node{
    int num,y,x,dir;
};
int n,k;
int map[13][13];
vector<int> board[13][13];
Node mal[11];
int diry[5]={0,0,0,-1,1};
int dirx[5]={0,1,-1,0,0};
int answer=0;
int check(){
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            if(board[y][x].size()>=4) return 1;
        }
    }
    return 0;
}
void white(Node now,int dy,int dx){
    // cout<<"dy: "<<dy<<" dx: "<<dx<<"\n";
    int idx=0;
    // cout<<"[white]\n";
    for(int i=0;i<board[now.y][now.x].size();i++){
        int up=board[now.y][now.x][i];
        // cout<<"up: "<<up<<"\n";
        if(up==now.num){
            idx=i;
            break;
        }
    }
    for(int i=idx;i<board[now.y][now.x].size();i++){
        board[dy][dx].push_back(board[now.y][now.x][i]);
        Node next=mal[board[now.y][now.x][i]];
        mal[board[now.y][now.x][i]]={board[now.y][now.x][i],dy,dx,next.dir};
    }
    for(int i=idx;i<board[now.y][now.x].size();i++){
        board[now.y][now.x].erase(board[now.y][now.x].begin()+i);
        i--;
    }
    
    
}

void red(Node now,int dy,int dx){
    int idx=0;
    // cout<<"[red]\n";
    for(int i=0;i<board[now.y][now.x].size();i++){
        int up=board[now.y][now.x][i];
        // cout<<"*up: "<<up<<"\n";
        if(up==now.num){
            idx=i;
            break;
        }
    }
    // cout<<"*idx: "<<idx<<"\n";
    for(int i=board[now.y][now.x].size()-1;i>=idx;i--){
        // cout<<"*"<<board[now.y][now.x][i]<<"\n";
        board[dy][dx].push_back(board[now.y][now.x][i]);
        Node next=mal[board[now.y][now.x][i]];
        mal[board[now.y][now.x][i]]={board[now.y][now.x][i],dy,dx,next.dir};
    }
    for(int i=idx;i<board[now.y][now.x].size();i++){
        board[now.y][now.x].erase(board[now.y][now.x].begin()+i);
        i--;
    }
    // for(int y=1;y<=n;y++){
    //     for(int x=1;x<=n;x++){
    //         cout<<board[y][x].size()<<" ";
    //     }
    //     cout<<"\n";
    // }
}

void blue(Node now){
    // cout<<"[blue]\n";
    if(now.dir==1) now.dir=2;
    else if(now.dir==2) now.dir=1;
    else if(now.dir==3) now.dir=4;
    else if(now.dir==4) now.dir=3;
    // cout<<"now.dir: "<<now.dir<<"\n";
    int dy=diry[now.dir]+now.y;
    int dx=dirx[now.dir]+now.x;
    // cout<<"dy: "<<dy<<" dx: "<<dx<<"\n";
    mal[now.num].dir=now.dir;
    if(dy<1||dx<1||dy>n||dx>n) return ;
    if(map[dy][dx]==0) white(now,dy,dx);
    else if(map[dy][dx]==1) red(now,dy,dx);
    // for(int y=1;y<=n;y++){
    //     for(int x=1;x<=n;x++){
    //         cout<<board[y][x].size()<<" ";
    //     }
    //     cout<<"\n";
    // }
}
int run(){
    for(int i=1;i<=k;i++){
        Node now=mal[i];
        // printf("[now] - num: %d y: %d x: %d dir: %d\n",now.num,now.y,now.x,now.dir);
        int dy=now.y+diry[now.dir];
        int dx=now.x+dirx[now.dir];
        if(dy<1||dx<1||dy>n||dx>n){
            // 체스판을 벗어나는 경우 == 파란색과 같은 경우
            blue(now);
        }
        else if(map[dy][dx]==0){
            // 흰색
            white(now,dy,dx);
        }
        else if(map[dy][dx]==1){
            // 빨간색
            red(now,dy,dx);
        }
        else if(map[dy][dx]==2){
            // 파란색
            blue(now);
        }
        // for(int y=1;y<=n;y++){
        //     for(int x=1;x<=n;x++){
        //         cout<<board[y][x].size()<<" ";
        //     }
        //     cout<<"\n";
        // }
        if(check()==1) return 1;
    }
    return 0;
}

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin>>map[y][x];
        }
    }
    for(int i=1;i<=k;i++){
        int r,c,dir;
        cin>>r>>c>>dir;
        mal[i]={i,r,c,dir};
        board[r][c].push_back(i);
    }

    while(answer<1000){
        answer++;
        if(run()==1) break;
        
    }
    if(answer>=1000) cout<<"-1\n";
    else cout<<answer<<"\n";
    return 0;
}