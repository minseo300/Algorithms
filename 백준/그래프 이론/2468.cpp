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

int map[100][100];
int map2[100][100];
int used[100][100];
struct Node{
    int y,x;
};
queue<Node> q;
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    int maxH=-21e8;
    int ans=-21e8;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
            maxH=max(maxH,map[y][x]);
        }
    }
    for(int h=0;h<=maxH;h++){
        memset(used,0,sizeof(used));
        memset(map2,0,sizeof(map2));
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(map[y][x]<=h) map2[y][x]=0;
                else map2[y][x]=map[y][x];
            }
        }
        int cnt=0;
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(used[y][x]==1) continue;
                if(map2[y][x]==0) continue;

                q.push({y,x});
                while(!q.empty()){
                    Node now=q.front();
                    q.pop();

                    for(int d=0;d<4;d++){
                        int dy=now.y+direct[d][0];
                        int dx=now.x+direct[d][1];

                        if(dy<0||dx<0||dy>=n||dx>=n) continue;
                        if(used[dy][dx]==1) continue;
                        if(map2[dy][dx]==0) continue;

                        q.push({dy,dx});
                        used[dy][dx]=1;
                    }

                }
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}