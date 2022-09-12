#include<iostream>

using namespace std;

int h,w;
int ny,nx;
int nd; // 현재 방향
int map[4][4];
int direct[4][2]={
    -1,0,
    0,-1,
    1,0,
    0,1
};
int used[4][4];
int rotate(int d){
    int nd;
    nd=d-1;
    if(nd==-1) nd=3;

    return nd; 
}
int back(int d){
    int b;
    if(d==0) b=2;
    else if(d==1) b=3;
    else if(d==2) b=0;
    else if(d==3) b=1;

    return b;
}
int main(){
    freopen( "input.txt", "r", stdin);

    cin>>h>>w;
    cin>>ny>>nx>>nd;

    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            cin>>map[y][x];
        }
    }
    int cnt=1;
    used[ny][nx]=1;
    int turn=0;
    while(true){
        //1. 왼쪽으로 회전
        nd=rotate(nd);
        // 회전해서 갈 수 있는 칸 좌표 구하기
        int dy=direct[nd][0]+ny;
        int dx=direct[nd][1]+nx;

        if(dy<0||dx<0||dy>=h||dx>=w) continue;
        
        // 회전해서 가려는 죄표가 갈 수 있는 칸이면 간다.
        if(map[dy][dx]==0&&used[dy][dx]==0){
            //2. 좌표 이동
            ny=dy;
            nx=dx;
            used[dy][dx]=1; // 방문한 곳 방문 처리
            cnt++;
            turn=0;
            continue;
        }
        // 못가면 turn 증가
        else turn++;
        // turn이 4라는 것은 회전한 네 방향 모두 갈 수 없다는 뜻
        if(turn==4){
            // 모두 갈 수 없으면 뒤로 한칸 가야함.
            int b=back(nd);
            // 뒤로 한 칸 가려는 좌표 구하기
            dy=ny+direct[b][0];
            dx=nx+direct[b][1];

            // 뒤로 가려는 좌표 갈 수 있으면 가기
            if(map[dy][dx]==0){
                ny=dy;
                nx=dx;
            }
            // 갈 수 없으면(바다면) 이동 그만!
            else break;
            turn=0;
        } 
    }
    cout<<cnt<<"\n";

    return 0;
}