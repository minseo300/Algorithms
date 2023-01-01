#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<vector<int> > map;
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int used[26][26]={0,};
struct Node{
    int y,x;
};
queue<Node> q;
priority_queue<int,vector<int>,greater<int> > cnts;
int flood(int ny,int nx){
    used[ny][nx]=1;
    Node nn={ny,nx};
    q.push(nn);
    int cnt=1;
    while(!q.empty()){
        Node node=q.front();
        q.pop();

        for(int d=0;d<4;d++){
            int dy=node.y+direct[d][0];
            int dx=node.x+direct[d][1];

            if(dy<0||dx<0||dy>=n||dx>=n) continue;
            if(map[dy][dx]==0) continue;
            if(used[dy][dx]==1) continue;

            Node n={dy,dx};
            q.push(n);
            used[dy][dx]=1;
            cnt++;
        }
    }

    return cnt;
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    map.assign(n,vector<int>(n));

    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        for(int j=0;j<n;j++) map[i][j]=input[j]-'0';
    }
    
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(map[y][x]==0) continue;
            if(used[y][x]==1) continue;
            
            
            
            int cnt=flood(y,x);
            cnts.push(cnt);
        }
    }
    cout<<cnts.size()<<"\n";
    while(!cnts.empty()){
        cout<<cnts.top()<<"\n";
        cnts.pop();
    }
    return 0;
}