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

int r,c,n;
struct Node{
    int case_,time;
};
struct Node2{
    int y,x;
};
Node map[202][202];
int visited[202][202];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
void install(int time){
    // cout<<"install\n";
    for(int y=0;y<r;y++){
        for(int x=0;x<c;x++){
            if(map[y][x].case_==1) continue;
            map[y][x]={1,time};
        }
    }
}
void bomb(int time){
    // cout<<"bomb\n";
    queue<Node2> q;
    for(int y=0;y<r;y++){
        for(int x=0;x<c;x++){
           if(map[y][x].case_==1&&time-3==map[y][x].time){
                q.push({y,x});
           }
        }
    }
    while(!q.empty()){
        Node2 now=q.front();
        q.pop();

        map[now.y][now.x]={0,0};
        for(int d=0;d<4;d++){
            int dy=now.y+diry[d];
            int dx=now.x+dirx[d];

            if(dy<0||dx<0||dy>=r||dx>=c) continue;

            map[dy][dx]={0,0};
        }

    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>r>>c>>n;
    string s;
    for(int y=0;y<r;y++){
        cin>>s;
        for(int x=0;x<c;x++){
            if(s[x]=='O') map[y][x]={1,0};
            else map[y][x]={0,0};
        }
    }

    for(int i=2;i<=n;i++){
        if(i%2==0){
            install(i);
        }
        else bomb(i);

       
    }
    for(int y=0;y<r;y++){
        string ss="";
        for(int x=0;x<c;x++){
            if(map[y][x].case_==0) ss+=".";
            else ss+="O";
        }
        cout<<ss<<"\n";
    }

    cout<<"\n";
    return 0;
}
