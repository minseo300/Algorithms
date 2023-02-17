#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int y,x,time;
};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int n,m;
int times[100][100];
bool operator<(Node v,Node t){
    return v.time>t.time;
}
void init(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++) times[i][j]=21e8;
    }
}
int solution(vector<string> maps) {
    int answer = 0;
    vector<vector<int>> map;
    Node start,end,l;
    n=maps.size();
    m=maps[0].size();
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                start.y=i;
                start.x=j;
                start.time=0;
            } 
            else if(maps[i][j]=='L'){
                l.y=i;
                l.x=j;
                l.time=0;
            }
            else if(maps[i][j]=='E'){
                end.y=i;
                end.x=j;
                end.time=0;
            }
            times[i][j]=21e8;
        }
    }
    priority_queue<Node> q;
    q.push(start);
    while(!q.empty())
    {
        Node now=q.top();
        q.pop();
        
        if(times[now.y][now.x]<now.time) continue;
        
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];
            
            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(maps[dy][dx]=='X') continue;
            
            if(times[dy][dx]>now.time+1){
                times[dy][dx]=now.time+1;
                q.push({dy,dx,now.time+1});
            }
        }
    }
    int mid=times[l.y][l.x];
    cout<<mid<<"\n";
    init();
    q.push(l);
    while(!q.empty())
    {
        Node now=q.top();
        q.pop();
        
        if(times[now.y][now.x]<now.time) continue;
        
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];
            
            if(dy<0||dx<0||dy>=n||dx>=m) continue;
            if(maps[dy][dx]=='X') continue;
            
            if(times[dy][dx]>now.time+1){
                times[dy][dx]=now.time+1;
                q.push({dy,dx,now.time+1});
            }
        }
    }
    int end_t=times[end.y][end.x];
    if(mid==21e8||end_t==21e8) answer=-1;
    else answer=mid+end_t;
    return answer;
}