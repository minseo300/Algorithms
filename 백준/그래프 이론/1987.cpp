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

char map[21][21];
int map2[21][21];
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
struct Node{
    int y,x,cnt;
};
queue<Node> q;
int used[100];
int ans=0;
int r, c; // 세로, 가로

void dfs(int x,int y,int cnt){
    ans=max(ans,cnt);

    for(int d=0;d<4;d++){
        int dy=y+direct[d][0];
        int dx=x+direct[d][1];

        if(dy<1||dx<1||dy>r||dx>c) continue;
        if(used[map[dy][dx]]==1) continue;

        used[map[dy][dx]]=1;
        dfs(dx,dy,cnt+1);
        used[map[dy][dx]]=0;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>r>>c;
    for(int y=1;y<=r;y++){
        string s;
        cin>>s;
        for(int x=0;x<c;x++){
            map[y][x+1]=s[x];
        }
    }
    used[map[1][1]]=1;
    dfs(1,1,1);
   
    cout<<ans<<"\n";
    return 0;
}