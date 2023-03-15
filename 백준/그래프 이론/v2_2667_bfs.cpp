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

int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
int n;
int map[25][25];
int visited[25][25];
struct Node{
    int y,x,cnt;
};
vector<int> ans;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            map[i][j]=s[j]-'0';
        }
    }
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(visited[y][x]==1) continue;
            if(map[y][x]==0) continue;
            // cout<<map[y][x]<<"\n";
            queue<Node> q;
            visited[y][x]=1;
            q.push({y,x,1});
            int count=0;
            while(!q.empty()){
                Node now=q.front();
                // printf("[now] y: %d x: %d\n",now.y,now.x);
                q.pop();
                count++;
                for(int d=0;d<4;d++){
                    int dy=diry[d]+now.y;
                    int dx=dirx[d]+now.x;
                    if(dy<0||dx<0||dy>=n||dx>=n) continue;
                    if(map[dy][dx]==0) continue;
                    if(visited[dy][dx]==1) continue;

                    q.push({dy,dx,now.cnt+1});
                    visited[dy][dx]=1;
                }
            }
            // cout<<"-"<<count<<"\n";
            ans.push_back(count);

        }
    }
    cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
