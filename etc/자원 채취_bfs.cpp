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

int n,k; // 지도 크기, 채취하기를 원하는 지점의 수
char map[1000][1000];
int ret[1000][1000];
int visited[1000][1000];
char ans[1000][1000];
struct Node{
    int y,x,dis;
};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
bool compare(Node t, Node v){
    if(t.dis==v.dis){
        if(t.y==v.y) return t.x<v.x;
        return t.y<v.y;
    }
    return t.dis<v.dis;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    Node tamsa;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='B'){
                // map[i][j]=1; // 탐사 기지를 설치할 위치 B
                tamsa={i,j,0};
            } 
            // else if(s[j]=='O') map[i][j]=2; // 자원이 위치하고 있는 지점
            // else if(s[j]=='.') map[i][j]=0; // 빈 공간
            map[i][j]=s[j];
        }
    }
    queue<Node> q;
    q.push(tamsa);
    visited[tamsa.y][tamsa.x]=1;
    vector<Node> candis;
    while(!q.empty()){
        Node now=q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=n) continue;
            if(visited[dy][dx]==1) continue;
            
            q.push({dy,dx,now.dis+1});
            if(map[dy][dx]=='O') candis.push_back({dy,dx,now.dis+1});
            ret[dy][dx]=now.dis+1;
            visited[dy][dx]=1;
        }
    }
    if(candis.size()<k) cout<<"-1\n";
    else{
        sort(candis.begin(),candis.end(),compare);
        
        memcpy(ans,map,sizeof(map));
        for(int i=0;i<k;i++){
            Node now=candis[i];
            map[now.y][now.x]='X';
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<map[i][j];
            }
            cout<<"\n";
        }
    } 
    
    return 0;
}