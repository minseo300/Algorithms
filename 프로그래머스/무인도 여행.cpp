#include <string>
#include <vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int map[100][100];
int visited[100][100];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
struct Node{
    int y,x;
};
vector<int> solution(vector<string> maps) {
    int cols=maps[0].length();
    vector<int> answer;
    for(int y=0;y<maps.size();y++){
        for(int x=0;x<cols;x++){
            if(maps[y][x]=='X') map[y][x]=0;
            else map[y][x]=maps[y][x]-'0';
        }
    }
    queue<Node> q;
    for(int y=0;y<maps.size();y++){
        for(int x=0;x<cols;x++){
            if(map[y][x]>0&&visited[y][x]==0){
                q.push({y,x});
                visited[y][x]=1;
                int sum=map[y][x];
                while(!q.empty()){
                    Node now=q.front();
                    q.pop();
                    for(int d=0;d<4;d++){
                        int dy=diry[d]+now.y;
                        int dx=dirx[d]+now.x;
                        
                        if(dy<0||dx<0||dy>=maps.size()||dx>=cols) continue;
                        if(visited[dy][dx]==1) continue;
                        if(map[dy][dx]==0) continue;
                        
                        q.push({dy,dx});
                        visited[dy][dx]=1;
                        sum+=map[dy][dx];
                    }
                }
                answer.push_back(sum);
            }
        }
    }
    if(answer.size()==0) answer.push_back(-1);
    else{
        sort(answer.begin(),answer.end());
    }
    return answer;
}