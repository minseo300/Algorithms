#include <string>
#include <vector>
#include<cmath>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node{
    int y,x,num;
};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};

int map[5][5];
vector<Node> pars; // 응시자
int used[5][5];
int bfs(){
    
    for(int i=0;i<pars.size();i++){
        queue<Node> q;
        memset(used,0,sizeof(used));
        // cout<<"p: "<<pars[i].y<<" "<<pars[i].x<<"\n";
        q.push({pars[i].y,pars[i].x});
        used[pars[i].y][pars[i].x]=1;
        while(!q.empty()){
            Node now=q.front();
            // cout<<"now: "<<now.y<<" "<<now.x<<" "<<now.num<<"\n";
            q.pop();
            if(now.num==2) continue;
            for(int d=0;d<4;d++){
                int dy=now.y+direct[d][0];
                int dx=now.x+direct[d][1];
                
                if(dy<0||dx<0||dy>=5||dx>=5) continue;
                if(map[dy][dx]==2) continue;
                if(used[dy][dx]==1) continue;
                
                if(map[dy][dx]==0) return 0;
                
                q.push({dy,dx,now.num+1});
                used[dy][dx]=1;
            }
        }
    } 
    return 1;
    
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        int num=0;
        vector<string> case_=places[i];
        pars.clear();
        for(int j=0;j<5;j++){
            string s=case_[j];
            for(int k=0;k<5;k++){
                if(s[k]=='P') {
                    pars.push_back({j,k,0});
                    map[j][k]=0; // 응시자
                }
                else if(s[k]=='O'){
                    map[j][k]=1; // 빈 테이블
                }
                else if(s[k]=='X'){
                    map[j][k]=2; // 파티션
                }
            }
        }
        
        if(bfs()) answer.push_back(1);
        else answer.push_back(0);
        
    }
    return answer;
}