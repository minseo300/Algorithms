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

int n,l,r;
int map[51][51];
struct Node{
    int y,x,num;
};
int answer=0;
int used[51][51]={0,};
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int map2[51][51];
int flag=1;
void init(){
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            used[y][x]=0;
        }
    }
}
vector<Node> pops; 
int bfs(int y,int x){
    queue<Node> q;
    q.push({y,x,0});
    used[y][x]=1;
    pops.push_back({y,x,map[y][x]});
    int total=0;
    total+=map[y][x];
  
    while(!q.empty()){
        Node now=q.front();
        q.pop();
        int cnt=0;
        for(int d=0;d<4;d++){
            int dy=now.y+direct[d][0];
            int dx=now.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=n) continue;
            if(used[dy][dx]==1) continue;
            if(abs(map[now.y][now.x]-map[dy][dx])<l||abs(map[now.y][now.x]-map[dy][dx])>r) continue;
            
            used[dy][dx]=1;
            pops.push_back({dy,dx,map[dy][dx]});
            total+=map[dy][dx];
            q.push({dy,dx,now.num});
        }
    }
    return total;

}

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>l>>r;

    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
        }
    }
    while(flag){
        flag=0;
        init();
        // for(int y=0;y<n;y++){
        //     for(int x=0;x<n;x++){
        //         cout<<map[y][x]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(used[y][x]==1) continue;

                pops.clear();
                int total=bfs(y,x);
        
                if(pops.size()>=2){
                    flag=1;
                    int avg=total/pops.size();
                    for(int i=0;i<pops.size();i++){
                        map[pops[i].y][pops[i].x]=avg;
                    }
                }
                
            }
        }
        if(flag) answer++;
    }
   
   cout<<answer<<"\n";

    
    
    return 0;
}